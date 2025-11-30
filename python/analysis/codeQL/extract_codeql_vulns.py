import os
import json
import csv

import pandas as pd
import requests
from typing import List, Dict, Any

GITHUB_API_BASE = "https://api.github.com"

# Static settings
owner = "mohsystem"
repo = "llm-generated-code-c-cpp"    # llm-generated-code-java   llm-generated-code-python     llm_generated_code_c  llm-generated-code-c-cpp ==>cpp
excel_path = f"./codeql_report_{repo}.xlsx"
token = "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"

def get_github_token() -> str:
    return token


# ---------------------------------------------------------------------------
# API Fetch
# ---------------------------------------------------------------------------
def list_code_scanning_alerts(owner: str, repo: str) -> List[Dict[str, Any]]:
    token = get_github_token()
    url = f"{GITHUB_API_BASE}/repos/{owner}/{repo}/code-scanning/alerts"

    headers = {
        "Accept": "application/vnd.github+json",
        "Authorization": f"Bearer {token}",
        "X-GitHub-Api-Version": "2022-11-28",
    }

    params = {"per_page": 100, "page": 1}
    alerts: List[Dict[str, Any]] = []

    while True:
        res = requests.get(url, headers=headers, params=params, timeout=30)
        if res.status_code != 200:
            raise RuntimeError(f"GitHub API error {res.status_code}: {res.text}")

        page_data = res.json()
        if not page_data:
            break

        alerts.extend(page_data)

        if "next" in res.links:
            params["page"] += 1
        else:
            break

    return alerts


# ---------------------------------------------------------------------------
# CWE extraction
# ---------------------------------------------------------------------------
def extract_cwes(tags: List[str]) -> List[str]:
    cwes = []
    for tag in tags or []:
        if "cwe" in tag.lower():
            cwes.append(tag.split("/")[-1].upper())
    seen = set()
    unique = []
    for c in cwes:
        if c not in seen:
            seen.add(c)
            unique.append(c)
    return unique


# ---------------------------------------------------------------------------
# Filename parsing: TaskXXX_VENDOR_model_name
# ---------------------------------------------------------------------------
def parse_task_filename(filename: str) -> Dict[str, Any]:
    result = {
        "file_name_full": filename,
        "task_number": None,
        "model_vendor": None,
        "model_name": None,
    }

    if not filename.lower().startswith("task"):
        return result

    name_no_ext = filename.rsplit(".", 1)[0]
    parts = name_no_ext.split("_")

    if len(parts) < 3:
        return result

    # Task number
    digits = "".join(x for x in parts[0] if x.isdigit())
    if digits.isdigit():
        result["task_number"] = int(digits)

    # Vendor
    result["model_vendor"] = parts[1]

    # Model name
    result["model_name"] = "_".join(parts[2:])
    return result


# ---------------------------------------------------------------------------
# Path parsing
# ---------------------------------------------------------------------------
def build_path_fields(path: str) -> Dict[str, Any]:
    fields: Dict[str, Any] = {}

    if not path:
        fields["file_name"] = None
        fields["parent_folder"] = None
        return fields

    file_name = os.path.basename(path)
    dir_path = os.path.dirname(path)

    folders = dir_path.split("/") if dir_path else []
    parent_folder = folders[-1] if folders else None

    fields["file_name"] = file_name
    fields["parent_folder"] = parent_folder

    # folder_level_x
    for i, folder in enumerate(folders, start=1):
        fields[f"folder_level_{i}"] = folder

    # Add task parsing
    fields.update(parse_task_filename(file_name))
    return fields


# ---------------------------------------------------------------------------
# Security detection (your requirement)
# ---------------------------------------------------------------------------
def is_security_alert(alert: dict) -> bool:
    rule = alert.get("rule") or {}
    tags = rule.get("tags") or []

    # check for 'security' tag
    if any(t.lower() == "security" for t in tags):
        return True

    # check for security_severity_level
    sec = rule.get("security_severity_level") or alert.get("security_severity_level")
    if sec:
        return True

    return False


def get_security_severity(alert: dict) -> str:
    """
    Returns: critical, high, medium, low, or none
    """
    rule = alert.get("rule") or {}
    sec = rule.get("security_severity_level") or alert.get("security_severity_level")
    if sec:
        return sec.lower()
    return "none"


def compute_display_severity(alert: dict) -> str:
    """
    GitHub UI severity:
    Prefer security_severity_level if present.
    Otherwise fall back to rule.severity.
    """
    sec = get_security_severity(alert)
    if sec != "none":
        return sec.capitalize()

    rule = (alert.get("rule") or {}).get("severity")
    if rule:
        return rule.capitalize()

    return "Unknown"


# ---------------------------------------------------------------------------
# Normalize alert into one spreadsheet row
# ---------------------------------------------------------------------------
def normalize_alert(alert: Dict[str, Any]) -> Dict[str, Any]:
    rule = alert.get("rule", {}) or {}
    instance = alert.get("most_recent_instance", {}) or {}
    location = instance.get("location", {}) or {}
    message = instance.get("message", {}) or {}

    tags = rule.get("tags", []) or []
    cwes = extract_cwes(tags)

    path = location.get("path") or ""
    path_fields = build_path_fields(path)

    tool_name = (alert.get("tool") or {}).get("name")

    record = {
        "alert_number": alert.get("number"),
        "state": alert.get("state"),

        # Severities
        "is_security_alert": is_security_alert(alert),
        "security_severity_level": get_security_severity(alert),
        "rule_severity": rule.get("severity"),
        "display_severity": compute_display_severity(alert),

        # Rule details
        "rule_id": rule.get("id"),
        "rule_name": rule.get("name"),
        "rule_description": rule.get("description"),

        # Tool info
        "tool_name": tool_name,

        # CWEs and tags
        "cwes": ", ".join(cwes),
        "tags": ", ".join(tags),

        # File and location
        "file_path": path,
        "start_line": location.get("start_line"),
        "end_line": location.get("end_line"),

        # Content
        "message": message.get("text"),

        # Metadata
        "html_url": alert.get("html_url"),
        "created_at": alert.get("created_at"),
        "dismissed_at": alert.get("dismissed_at"),
        "dismissed_reason": alert.get("dismissed_reason"),
    }

    record.update(path_fields)
    return record


# ---------------------------------------------------------------------------
# Excel writer
# ---------------------------------------------------------------------------
def write_excel(records: List[Dict[str, Any]], output_path: str) -> None:
    if not records:
        print("No alerts found.")
        return

    df = pd.DataFrame(records)

    preferred = [
        "alert_number",
        "state",
        "display_severity",
        "security_severity_level",
        "rule_severity",
        "is_security_alert",
        "rule_id",
        "rule_name",
        "rule_description",
        "tool_name",
        "cwes",
        "tags",
        # "file_path",
        "file_name_full",
        "file_name",
        "parent_folder",
        "task_number",
        "model_vendor",
        "model_name",
        "folder_level_1",
        "folder_level_2",
        # "folder_level_3",
        # "folder_level_4",
        "start_line",
        # "end_line",
        "message",
        "html_url",
        "created_at",
        # "dismissed_at",
        # "dismissed_reason",
    ]

    existing = df.columns.tolist()
    ordered = [c for c in preferred if c in existing]
    remaining = [c for c in existing if c not in ordered]

    df = df[ordered + remaining]
    df.to_excel(output_path, index=False)

    print(f"Excel exported: {output_path}")


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------
def main():
    print(f"Fetching alerts for {owner}/{repo}...")
    alerts = list_code_scanning_alerts(owner, repo)
    print(f"Total alerts: {len(alerts)}")

    normalized = [normalize_alert(a) for a in alerts]
    write_excel(normalized, excel_path)


if __name__ == "__main__":
    main()