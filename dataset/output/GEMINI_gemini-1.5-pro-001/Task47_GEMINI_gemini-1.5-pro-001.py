import requests
from bs4 import BeautifulSoup
import sqlite3

# Target website and data to scrape
url = "https://www.example.com"  # Replace with the target website
table_name = "scraped_data"
data_attributes = {"class": "example-class"}  # Replace with actual attributes

# Database setup
conn = sqlite3.connect('scraped_data.db')
cursor = conn.cursor()
cursor.execute(f'''CREATE TABLE IF NOT EXISTS {table_name} (id INTEGER PRIMARY KEY AUTOINCREMENT, data TEXT)''')

# Data scraping and storage
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')

data_elements = soup.find_all(attrs=data_attributes)
for element in data_elements:
    data = element.text.strip()
    cursor.execute(f"INSERT INTO {table_name} (data) VALUES (?)", (data,))

conn.commit()
conn.close()
print("Data scraped and stored successfully!")