import sys
import requests
import json

if len(sys.argv) != 2:
    print("Usage: python script.py <URL>")
    sys.exit(1)

url = sys.argv[1]
response = requests.get(url)

try:
    data = response.json()
    print(json.dumps(data, indent=4))
except json.JSONDecodeError:
    print("Failed to parse JSON from the response.")