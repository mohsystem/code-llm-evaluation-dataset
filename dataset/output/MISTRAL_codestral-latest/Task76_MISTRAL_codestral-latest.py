import requests
from bs4 import BeautifulSoup
import sys

def get_page_title(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    title = soup.title.string
    return title

if __name__ == "__main__":
    url = sys.argv[1]
    print(get_page_title(url))