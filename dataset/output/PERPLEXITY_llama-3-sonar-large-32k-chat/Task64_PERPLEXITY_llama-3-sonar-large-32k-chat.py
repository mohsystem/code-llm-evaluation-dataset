import sys
import requests
import json

def read_json_from_url(url):
    response = requests.get(url)
    return json.loads(response.text)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <url>")
        sys.exit(1)
    url = sys.argv[1]
    json_obj = read_json_from_url(url)
    print(json_obj)