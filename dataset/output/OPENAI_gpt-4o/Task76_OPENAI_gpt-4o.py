import sys
import requests
from bs4 import BeautifulSoup

if len(sys.argv) != 2:
    print("Usage: python script.py <URL>")
    sys.exit(1)

url = sys.argv[1]
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')
title = soup.title.string

print(title)