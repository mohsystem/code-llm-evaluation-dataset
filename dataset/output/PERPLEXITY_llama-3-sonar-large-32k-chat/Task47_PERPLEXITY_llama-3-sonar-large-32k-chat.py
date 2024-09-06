import requests
from bs4 import BeautifulSoup
import sqlite3

# Send a GET request
response = requests.get("https://www.example.com")

# If the GET request is successful, the status code will be 200
if response.status_code == 200:
    # Get the content of the response
    page_content = response.content

    # Create a BeautifulSoup object and specify the parser
    soup = BeautifulSoup(page_content, 'html.parser')

    # Find the data you want to scrape
    data = soup.find_all('div', {'class': 'data'})

    # Connect to the SQLite database
    conn = sqlite3.connect('database.db')
    c = conn.cursor()

    # Create table
    c.execute('''CREATE TABLE IF NOT EXISTS data
                 (id INTEGER PRIMARY KEY, data TEXT)''')

    # Insert data into the table
    for i, d in enumerate(data):
        c.execute("INSERT INTO data VALUES (?, ?)", (i, d.text))

    # Save the changes
    conn.commit()

    # Close the connection
    conn.close()