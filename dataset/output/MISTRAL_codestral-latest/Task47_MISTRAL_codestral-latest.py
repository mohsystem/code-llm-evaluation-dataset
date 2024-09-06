# Python
import requests
from bs4 import BeautifulSoup
import sqlite3

# Connect to SQLite database
conn = sqlite3.connect('website_data.db')
c = conn.cursor()

# Create table
c.execute('''CREATE TABLE IF NOT EXISTS data
             (title TEXT, link TEXT)''')

# Scrape data
url = 'http://example.com'
response = requests.get(url)
soup = BeautifulSoup(response.text, 'html.parser')

for item in soup.find_all('div', class_='item'):
    title = item.find('h2').text
    link = item.find('a')['href']

    # Insert data into table
    c.execute("INSERT INTO data VALUES (?, ?)", (title, link))

# Commit changes and close connection
conn.commit()
conn.close()