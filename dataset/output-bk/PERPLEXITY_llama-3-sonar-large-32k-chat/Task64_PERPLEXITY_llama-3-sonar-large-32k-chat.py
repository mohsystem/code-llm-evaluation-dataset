import sys
import requests
import json

if len(sys.argv) != 2:
    print("Usage: python3 main.py <url>")
    exit(1)

url = sys.argv[1]
response = requests.get(url)
if response.status_code == 200:
    print(json.dumps(response.json(), indent=4))
else:
    print("Failed to retrieve data:", response.status_code)