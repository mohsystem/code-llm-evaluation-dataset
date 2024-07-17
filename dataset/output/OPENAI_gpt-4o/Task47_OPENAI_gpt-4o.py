import sqlite3
import requests
from bs4 import BeautifulSoup

def scrape(url, db_conn):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    data = [p.text for p in soup.select('p')]

    with db_conn:
        db_conn.execute('CREATE TABLE IF NOT EXISTS data (info TEXT)')
        db_conn.executemany('INSERT INTO data (info) VALUES (?)', [(d,) for d in data])

def main():
    url = 'https://example.com'
    db_conn = sqlite3.connect('sample.db')
    scrape(url, db_conn)
    db_conn.close()

if __name__ == '__main__':
    main()