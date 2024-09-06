import requests
import sqlite3
from bs4 import BeautifulSoup

# Function to scrape data from a given URL
def scrape_data(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    data = []

    # This example assumes you're scraping list items (li) from the webpage
    for item in soup.find_all('li'):
        data.append(item.text)

    return data

# Function to store data in a local SQLite database
def store_data(db_name, data):
    conn = sqlite3.connect(db_name)
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS scraped_data (content TEXT)''')

    for item in data:
        c.execute("INSERT INTO scraped_data (content) VALUES (?)", (item,))

    conn.commit()
    conn.close()

# Example
url = 'https://example.com'
db_name = 'scraped_data.db'
data = scrape_data(url)
store_data(db_name, data)