import sys
import json
import urllib.request

def read_json_from_url(url):
    with urllib.request.urlopen(url) as response:
        data = response.read().decode("utf-8")
        return json.loads(data)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Please provide a URL as a command line argument.")
        sys.exit(1)

    url = sys.argv[1]
    json_data = read_json_from_url(url)
    print(json.dumps(json_data, indent=4))