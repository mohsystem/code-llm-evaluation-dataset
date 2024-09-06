
import sys
import json
import urllib.request

def fetch_json(url):
    with urllib.request.urlopen(url) as response:
        data = response.read().decode('utf-8')
    return json.loads(data)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <url>")
        sys.exit(1)
    
    url = sys.argv[1]
    try:
        json_data = fetch_json(url)
        print(json.dumps(json_data, indent=2))
    except Exception as e:
        print(f"Error: {e}")
