
import requests
from bs4 import BeautifulSoup
import sqlite3

# Function to scrape data from website
def scrape_website(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    # Example: scraping all paragraph texts
    data = [p.text for p in soup.find_all('p')]
    return data

# Function to store data in SQLite database
def store_in_database(data):
    conn = sqlite3.connect('scraped_data.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS scraped_text\n                 (id INTEGER PRIMARY KEY, content TEXT)''')
    for item in data:
        c.execute("INSERT INTO scraped_text (content) VALUES (?)", (item,))
    conn.commit()
    conn.close()

# Main function
def main():
    url = "https://example.com"  # Replace with the website you want to scrape
    scraped_data = scrape_website(url)
    store_in_database(scraped_data)
    print("Data scraped and stored successfully.")

if __name__ == "__main__":
    main()
