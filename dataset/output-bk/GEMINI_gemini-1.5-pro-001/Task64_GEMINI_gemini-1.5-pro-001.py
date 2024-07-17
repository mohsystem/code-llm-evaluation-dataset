import json
import requests
import sys

def read_json_from_url(url):
    response = requests.get(url)
    response.raise_for_status()  # Raise an exception for bad status codes
    return response.json()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python your_script.py <url>")
        sys.exit(1)

    url = sys.argv[1]
    try:
        data = read_json_from_url(url)
        print(data)
    except requests.exceptions.RequestException as e:
        print(f"Error fetching or parsing JSON: {e}")