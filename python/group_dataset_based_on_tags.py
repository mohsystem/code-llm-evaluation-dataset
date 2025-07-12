import pandas as pd
import re
from collections import defaultdict
import matplotlib.pyplot as plt
from ace_tools import display_dataframe_to_user

# Load dataset
file_path = "/mnt/data/dataset-summary.xlsx"
df = pd.read_excel(file_path)

# Clean column names
df.columns = [col.strip() for col in df.columns]

# Fill NaNs and convert Tags to lowercase
df["Tags"] = df["Tags"].fillna("").str.lower()

# Define grouping rules
tag_groups = {
    "Data Structures and Algorithms": [
        "arrays", "array", "lists", "hashmaps", "hashmap", "sorting", "searching", "graphs", "graph", "binary search", "stack", "queue",
        "trees", "tree", "linked list", "binary search tree", "recursion", "data structures", "algorithms", "algorithm", "pathfinding",
        "dijkstra", "trie", "dynamic programming", "bitwise operations", "sequence analysis", "iteration", "optimization", "greedy"
    ],
    "Secure Coding (CWEs)": [
        "cwe", "cwe-", "common weakness enumeration"
    ],
    "Input and Output Handling": [
        "file", "file handling", "text processing", "email parsing", "api", "file upload", "data handling", "echo server",
        "path manipulation", "path traversal", "url fetching", "file reading", "file read", "file download", "archive extraction",
        "ftp connection", "server", "server programming"
    ],
    "Mathematics and Logic": [
        "mathematics", "math", "arithmetic", "formula", "geometry", "cube", "series", "average", "bit fields"
    ],
    "Concurrency and Synchronization": [
        "concurrency", "thread", "synchronization", "multithreading", "parallel", "race condition", "thread locks"
    ],
    "Web and Network Security": [
        "ssl/tls", "encryption", "password", "web scraping", "session management", "authentication", "xss", "sql injection", "csrf",
        "web security", "network", "token", "certificate", "authorization", "session", "host", "nosql", "ldap", "ssrf", "ip address",
        "firewall", "ssl", "jndi", "open redirect", "cookie", "cors"
    ],
    "Parsing and Validation": [
        "input validation", "regular expressions", "string manipulation", "json parsing", "xml parsing", "data validation",
        "type conversion", "string processing", "unicode", "base64 encoding", "text", "data sanitization", "logging"
    ],
    "Programming Systems and Utilities": [
        "programming systems", "error handling", "debugging", "monitoring", "system security", "exe execution",
        "deserialization", "object injection", "data conversion", "buffer", "memory", "memory management"
    ]
}

# Process each task and assign it to one or more grouped categories
group_assignment = defaultdict(set)

for i, row in df.iterrows():
    task_id = row["Task Number"]
    tags = re.split(r",\s*", str(row["Tags"]).lower())
    tags_set = set(tags)

    for group, keywords in tag_groups.items():
        for tag in tags_set:
            for keyword in keywords:
                if keyword in tag:
                    group_assignment[group].add(task_id)
                    break

# Prepare results for display
group_summary = [(group, len(tasks)) for group, tasks in group_assignment.items()]
group_summary.sort(key=lambda x: x[1], reverse=True)

summary_df = pd.DataFrame(group_summary, columns=["Group", "Unique Task Count"])
display_dataframe_to_user(name="Grouped Tag Summary", dataframe=summary_df)
