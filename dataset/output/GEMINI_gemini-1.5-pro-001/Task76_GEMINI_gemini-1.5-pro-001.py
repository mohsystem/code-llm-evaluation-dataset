import requests
import sys
from bs4 import BeautifulSoup

def get_page_title(url):
    response = requests.get(url)
    response.raise_for_status()
    soup = BeautifulSoup(response.content, 'html.parser')
    title = soup.find('title')
    return title.text.strip() if title else None

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <url>")
        sys.exit(1)
    url = sys.argv[1]
    try:
        title = get_page_title(url)
        print(title)
    except requests.exceptions.RequestException as e:
        print(f"Error: {e}")