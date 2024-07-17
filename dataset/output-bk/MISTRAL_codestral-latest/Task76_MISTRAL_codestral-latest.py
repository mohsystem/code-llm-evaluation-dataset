import sys
import requests
from bs4 import BeautifulSoup

def get_page_title(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    title = soup.title.string
    return title

if __name__ == "__main__":
    if len(sys.argv) > 1:
        title = get_page_title(sys.argv[1])
        print("Page title: " + title)
    else:
        print("Please provide an URL as a command line argument.")