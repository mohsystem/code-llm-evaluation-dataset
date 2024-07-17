import json
import sys
import urllib.request

def fetch_json_from_url(url):
    with urllib.request.urlopen(url) as response:
        data = response.read().decode()
        return json.loads(data)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <URL>")
        sys.exit(1)

    url = sys.argv[1]
    json_obj = fetch_json_from_url(url)
    print(json.dumps(json_obj, indent=2))