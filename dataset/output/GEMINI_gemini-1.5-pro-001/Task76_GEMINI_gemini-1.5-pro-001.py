import requests
from bs4 import BeautifulSoup
import sys

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python script.py <url>")
        sys.exit(1)

    url = sys.argv[1]

    try:
        response = requests.get(url)
        response.raise_for_status()

        soup = BeautifulSoup(response.content, 'html.parser')
        title = soup.find('title').string.strip()

        print(title)

    except requests.exceptions.RequestException as e:
        print(f"Error: {e}")