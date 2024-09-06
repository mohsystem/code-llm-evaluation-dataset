import sys
import requests
import json

def get_json_from_url(url):
  """Fetches JSON data from the given URL and returns a JSON object.

  Args:
      url: The URL to fetch the JSON data from.

  Returns:
      A JSON object representing the data, or None if there's an error.
  """
  try:
    response = requests.get(url)
    response.raise_for_status()  # Raise an exception for HTTP errors
    return response.json()
  except requests.exceptions.RequestException as e:
    print(f"Error fetching data from {url}: {e}")
    return None

if __name__ == "__main__":
  if len(sys.argv) != 2:
    print("Usage: python your_script_name.py <url>")
    sys.exit(1)

  url = sys.argv[1]
  json_data = get_json_from_url(url)

  if json_data:
    print(json_data)