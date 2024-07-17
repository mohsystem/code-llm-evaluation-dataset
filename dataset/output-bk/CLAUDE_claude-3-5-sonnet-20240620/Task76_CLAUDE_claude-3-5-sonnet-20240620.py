
import sys
import requests
from bs4 import BeautifulSoup

def extract_title(url):
    try:
        response = requests.get(url)
        response.raise_for_status()
        soup = BeautifulSoup(response.text, \'html.parser\')
        title = soup.title.string if soup.title else "Title not found"
        return title.strip()
    except requests.RequestException as e:
        return f"Error: {str(e)}"

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <URL>")
        sys.exit(1)

    url = sys.argv[1]
    title = extract_title(url)
    print(f"Page Title: {title}")
