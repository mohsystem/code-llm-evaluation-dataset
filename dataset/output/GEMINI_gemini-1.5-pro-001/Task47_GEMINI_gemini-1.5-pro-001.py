import requests
from bs4 import BeautifulSoup
import sqlite3

# Target website URL
url = "https://www.example.com/" # Replace with the target website

# Send a GET request to the URL
response = requests.get(url)

# Parse the HTML content using BeautifulSoup
soup = BeautifulSoup(response.content, 'html.parser')

# Connect to the SQLite database (or create it if it doesn't exist)
conn = sqlite3.connect('data.db')
cursor = conn.cursor()

# Create a table to store the data (if it doesn't exist)
cursor.execute('''
    CREATE TABLE IF NOT EXISTS website_data (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        title TEXT,
        link TEXT
    )
''')

# Extract data (example: titles and links from 'a' tags)
for link in soup.find_all('a', href=True):
    title = link.text.strip()
    href = link['href']

    # Insert the data into the database
    cursor.execute("INSERT INTO website_data (title, link) VALUES (?, ?)", (title, href))

# Commit the changes to the database
conn.commit()

# Close the database connection
conn.close()

print("Data scraped and stored successfully!")