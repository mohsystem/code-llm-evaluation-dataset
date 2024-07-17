import sys
import requests
import re

if len(sys.argv) != 2:
    print("Usage: python3 main.py <url>")
    exit(1)

url = sys.argv[1]
response = requests.get(url)
if response.status_code == 200:
    match = re.search(r"<title>(.*?)</title>", response.text)
    if match:
        print(match.group(1))
    else:
        print("No title found")
else:
    print("Failed to retrieve page")