
import requests
from bs4 import BeautifulSoup
import sqlite3

# URL to scrape
url = "https://example.com"

# Send a GET request to the URL
response = requests.get(url)

# Parse the HTML content
soup = BeautifulSoup(response.content, \'html.parser\')

# Connect to SQLite database (or create it if it doesn\'t exist)
conn = sqlite3.connect(\'scraped_data.db\')
cursor = conn.cursor()

# Create table if it doesn\'t exist
cursor.execute(\'\'\'
    CREATE TABLE IF NOT EXISTS scraped_data
    (id INTEGER PRIMARY KEY AUTOINCREMENT,
     title TEXT,
     content TEXT)
\'\'\')

# Find all paragraph elements
paragraphs = soup.find_all(\'p\')

# Insert data into the database
for p in paragraphs:
    title = p.find(\'strong\').text if p.find(\'strong\') else \'\'
    content = p.text
    cursor.execute(\'INSERT INTO scraped_data (title, content) VALUES (?, ?)\', (title, content))

# Commit changes and close the connection
conn.commit()
conn.close()

print("Data scraped and stored successfully.")
