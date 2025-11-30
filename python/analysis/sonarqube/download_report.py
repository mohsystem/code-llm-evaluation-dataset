import os
import math
import requests
import pandas as pd
from datetime import datetime

SONARCLOUD_URL = "https://sonarcloud.io"
PROJECT_KEY = "mohkharma_llm-generated-code-cpp" #mohkharma_llm-generated-code-c  llm-generated-code-cpp  mohkharma_llm-generated-code-java   mohkharma_llm-generated-code-python
ORGANIZATION = PROJECT_KEY.split("_")[0]  # "mohkharma"

# Dynamic file name: sonarcloud_report_<project_key>_YYYYMMDD.xlsx
DATE_STR = datetime.now().strftime("%Y%m%d")
OUTPUT_FILE = f"sonarcloud_report_{PROJECT_KEY}_{DATE_STR}-detailed.xlsx"

TOKEN = os.getenv("SONARCLOUD_TOKEN")
HEADERS = {}
if TOKEN:
    HEADERS["Authorization"] = f"Bearer {TOKEN}"


def fetch_measures(project_key: str) -> dict:
    metrics = [
        "bugs",
        "vulnerabilities",
        "code_smells",
        "security_hotspots",
        "coverage",
        "duplicated_lines_density",
        "ncloc",
        "sqale_index",
        "reliability_rating",
        "security_rating",
        "sqale_rating",
    ]
    params = {"component": project_key, "metricKeys": ",".join(metrics)}
    url = f"{SONARCLOUD_URL}/api/measures/component"
    resp = requests.get(url, params=params, headers=HEADERS, timeout=30)
    resp.raise_for_status()
    data = resp.json()
    measures = {
        m["metric"]: m.get("value")
        for m in data.get("component", {}).get("measures", [])
    }
    measures["project_key"] = project_key
    return measures


def fetch_all_issues(project_key: str) -> list:
    """
    Fetch only OPEN vulnerability issues.
    """
    issues = []
    page_size = 500
    page = 1

    while True:
        params = {
            "componentKeys": project_key,
            "types": "VULNERABILITY",
            "statuses": "OPEN",
            "ps": page_size,
            "p": page,
        }
        url = f"{SONARCLOUD_URL}/api/issues/search"
        resp = requests.get(url, params=params, headers=HEADERS, timeout=60)
        resp.raise_for_status()
        data = resp.json()

        issues_page = data.get("issues", [])
        if not issues_page:
            break

        issues.extend(issues_page)

        paging = data.get("paging", {})
        total = paging.get("total", 0)
        pages = math.ceil(total / page_size)

        if page >= pages:
            break

        page += 1

    return issues


def fetch_rule_metadata(rule_key: str, cache: dict) -> dict:
    """
    Fetch rule metadata (CWE code only) from SonarCloud with caching.
    """
    if rule_key in cache:
        return cache[rule_key]

    url = f"{SONARCLOUD_URL}/api/rules/show"
    params = {"organization": ORGANIZATION, "key": rule_key}
    resp = requests.get(url, params=params, headers=HEADERS, timeout=20)

    if resp.status_code != 200:
        cache[rule_key] = {"cwe": ""}
        return cache[rule_key]

    data = resp.json().get("rule", {})
    security_standards = data.get("securityStandards", [])

    # Look for entries like "cwe:327" and turn into "CWE-327"
    cwe_code = ""
    for s in security_standards:
        s_lower = s.lower()
        if s_lower.startswith("cwe:"):
            number = s.split(":", 1)[1].strip()
            if number:
                cwe_code = f"CWE-{number}"
                break

    cache[rule_key] = {"cwe": cwe_code}
    return cache[rule_key]


def fetch_analyses(project_key: str) -> list:
    analyses = []
    page_size = 100
    page = 1

    while True:
        params = {"project": project_key, "ps": page_size, "p": page}
        url = f"{SONARCLOUD_URL}/api/project_analyses/search"
        resp = requests.get(url, params=params, headers=HEADERS, timeout=30)

        if resp.status_code == 403:
            break

        resp.raise_for_status()
        data = resp.json()
        analyses_page = data.get("analyses", [])
        if not analyses_page:
            break

        analyses.extend(analyses_page)

        paging = data.get("paging", {})
        total = paging.get("total", 0)
        pages = math.ceil(total / page_size)

        if page >= pages:
            break

        page += 1

    return analyses


def split_component_folders(component: str):
    """
    Return (file_name, folder_1, folder_2, folder_3)
    folder_1..3 are the last three folders before the file.
    If there are fewer than 3, missing ones are empty.
    """
    if not component:
        return "", "", "", ""

    if ":" in component:
        component = component.split(":", 1)[1]

    parts = component.strip("/").split("/")
    if not parts:
        return "", "", "", ""

    file_name = parts[-1]
    folder_parts = parts[:-1]

    last_three = folder_parts[-3:]
    last_three = [""] * (3 - len(last_three)) + last_three

    folder_1, folder_2, folder_3 = last_three
    return file_name, folder_1, folder_2, folder_3


def flatten_issues(raw_issues: list) -> pd.DataFrame:
    """
    Create Issues dataframe: one row per issue with CWE code, folders, file name, etc.
    """
    records = []
    rule_cache = {}

    for issue in raw_issues:
        rule_key = issue.get("rule", "")
        rule_meta = fetch_rule_metadata(rule_key, rule_cache)
        text_range = issue.get("textRange") or {}

        cwe = rule_meta.get("cwe", "")  # already like "CWE-327" or ""

        component = issue.get("component")
        file_name, folder_1, folder_2, folder_3 = split_component_folders(component)

        records.append(
            {
                "key": issue.get("key"),
                "rule": rule_key,
                "security_category": cwe,
                "severity": issue.get("severity"),
                "status": issue.get("status"),
                "resolution": issue.get("resolution"),
                "component": component,
                "folder_1": folder_1,
                "folder_2": folder_2,
                "folder_3": folder_3,
                "file_name": file_name,
                "message": issue.get("message"),
                "tags": ",".join(issue.get("tags") or []),
                "creationDate": issue.get("creationDate"),
                "updateDate": issue.get("updateDate"),
                "line": issue.get("line"),
                "startLine": text_range.get("startLine"),
                "endLine": text_range.get("endLine"),
                "project": issue.get("project"),
                "effort": issue.get("effort"),
                "assignee": issue.get("assignee"),
                "author": issue.get("author"),
            }
        )

    return pd.DataFrame(records)


def build_summary_pivot(issues_df: pd.DataFrame) -> pd.DataFrame:
    """
    Build Summary sheet.

    Rows:
      Group          -> folder_1
      LLM name       -> folder_3
      prompt method  -> folder_2

    For each CWE code (security_category):
      <CWE>_files -> number of unique files with this CWE in that row group
      <CWE>_total -> total number of issues with this CWE in that row group

    Also add severity columns:
      blocker_count, critical_count, major_count, minor_count, info_count
    """
    base_cols = ["Group", "LLM name", "prompt method"]

    if issues_df.empty:
        cols = base_cols + [
            "blocker_count",
            "critical_count",
            "major_count",
            "minor_count",
            "info_count",
        ]
        return pd.DataFrame(columns=cols)

    # Use only rows that have a CWE code
    cwe_df = issues_df[
        issues_df["security_category"].notna()
        & (issues_df["security_category"] != "")
        ].copy()

    # 1) Unique file counts per CWE
    cwe_unique = (
        cwe_df
        .groupby(
            ["folder_1", "folder_3", "folder_2", "security_category"],
            dropna=False,
        )["file_name"]
        .nunique()
        .reset_index(name="unique_files_count")
    )

    cwe_unique_pivot = cwe_unique.pivot_table(
        index=["folder_1", "folder_3", "folder_2"],
        columns="security_category",
        values="unique_files_count",
        fill_value=0,
        aggfunc="sum",
    ).reset_index()

    cwe_unique_pivot = cwe_unique_pivot.rename(
        columns={
            "folder_1": "Group",
            "folder_3": "LLM name",
            "folder_2": "prompt method",
        }
    )
    cwe_unique_pivot.columns.name = None

    # Rename CWE columns to *_files
    unique_cwe_cols_map = {}
    for col in cwe_unique_pivot.columns:
        if col not in base_cols:
            unique_cwe_cols_map[col] = f"{col}_files"
    cwe_unique_pivot = cwe_unique_pivot.rename(columns=unique_cwe_cols_map)

    # 2) Total issue counts per CWE
    cwe_total = (
        cwe_df
        .groupby(
            ["folder_1", "folder_3", "folder_2", "security_category"],
            dropna=False,
        )["key"]
        .count()
        .reset_index(name="vuln_total")
    )

    cwe_total_pivot = cwe_total.pivot_table(
        index=["folder_1", "folder_3", "folder_2"],
        columns="security_category",
        values="vuln_total",
        fill_value=0,
        aggfunc="sum",
    ).reset_index()

    cwe_total_pivot = cwe_total_pivot.rename(
        columns={
            "folder_1": "Group",
            "folder_3": "LLM name",
            "folder_2": "prompt method",
        }
    )
    cwe_total_pivot.columns.name = None

    # Rename CWE columns to *_total
    total_cwe_cols_map = {}
    for col in cwe_total_pivot.columns:
        if col not in base_cols:
            total_cwe_cols_map[col] = f"{col}_total"
    cwe_total_pivot = cwe_total_pivot.rename(columns=total_cwe_cols_map)

    # 3) Merge unique-files and total-vulns
    summary = pd.merge(
        cwe_unique_pivot,
        cwe_total_pivot,
        on=["Group", "LLM name", "prompt method"],
        how="outer",
    )

    # Fill NaNs in CWE-derived columns
    for col in summary.columns:
        if col not in base_cols:
            summary[col] = summary[col].fillna(0).astype(int)

    # 4) Severity counts per group
    sev_grouped = (
        issues_df
        .groupby(
            ["folder_1", "folder_3", "folder_2", "severity"],
            dropna=False,
        )["key"]
        .count()
        .reset_index(name="severity_count")
    )

    sev_pivot = sev_grouped.pivot_table(
        index=["folder_1", "folder_3", "folder_2"],
        columns="severity",
        values="severity_count",
        fill_value=0,
        aggfunc="sum",
    ).reset_index()

    sev_pivot = sev_pivot.rename(
        columns={
            "folder_1": "Group",
            "folder_3": "LLM name",
            "folder_2": "prompt method",
        }
    )
    sev_pivot.columns.name = None

    severity_col_map = {
        "BLOCKER": "blocker_count",
        "CRITICAL": "critical_count",
        "MAJOR": "major_count",
        "MINOR": "minor_count",
        "INFO": "info_count",
    }

    for sev, col_name in severity_col_map.items():
        if sev in sev_pivot.columns:
            sev_pivot = sev_pivot.rename(columns={sev: col_name})

    for col_name in severity_col_map.values():
        if col_name not in sev_pivot.columns:
            sev_pivot[col_name] = 0

    # Merge severity into summary
    summary = pd.merge(
        summary,
        sev_pivot[["Group", "LLM name", "prompt method"] + list(severity_col_map.values())],
        on=["Group", "LLM name", "prompt method"],
        how="outer",
    )

    for col in severity_col_map.values():
        summary[col] = summary[col].fillna(0).astype(int)

    # Final column ordering:
    # base cols, severity cols, then CWE_* columns sorted
    sev_cols = list(severity_col_map.values())
    cwe_cols = [
        c for c in summary.columns
        if c not in base_cols + sev_cols
    ]

    summary = summary[base_cols + sev_cols + sorted(cwe_cols)]

    return summary


def flatten_analyses(raw_analyses: list) -> pd.DataFrame:
    records = []
    for a in raw_analyses:
        events = a.get("events") or []
        event_types = ",".join(
            e.get("category", "") for e in events if e.get("category")
        )
        event_names = ",".join(
            e.get("name", "") for e in events if e.get("name")
        )
        records.append(
            {
                "analysis_key": a.get("key"),
                "date": a.get("date"),
                "projectVersion": a.get("projectVersion"),
                "buildString": a.get("buildString"),
                "revision": a.get("revision"),
                "event_categories": event_types,
                "event_names": event_names,
            }
        )
    return pd.DataFrame(records)


def main():
    print(f"Fetching measures for project {PROJECT_KEY}...")
    measures = fetch_measures(PROJECT_KEY)
    metrics_df = pd.DataFrame([measures])

    print("Fetching OPEN vulnerability issues...")
    raw_issues = fetch_all_issues(PROJECT_KEY)
    issues_df = flatten_issues(raw_issues) if raw_issues else pd.DataFrame()

    print("Building Summary sheet...")
    summary_df = build_summary_pivot(issues_df)

    print("Fetching analyses history...")
    raw_analyses = fetch_analyses(PROJECT_KEY)
    analyses_df = flatten_analyses(raw_analyses) if raw_analyses else pd.DataFrame()

    print(f"Writing data to {OUTPUT_FILE}...")
    with pd.ExcelWriter(OUTPUT_FILE, engine="openpyxl") as writer:
        metrics_df.to_excel(writer, sheet_name="Metrics", index=False)
        if not issues_df.empty:
            issues_df.to_excel(writer, sheet_name="Issues", index=False)
        if not summary_df.empty:
            summary_df.to_excel(writer, sheet_name="Summary", index=False)
        if not analyses_df.empty:
            analyses_df.to_excel(writer, sheet_name="Analyses", index=False)

    print("Done. Created:", OUTPUT_FILE)


if __name__ == "__main__":
    main()
