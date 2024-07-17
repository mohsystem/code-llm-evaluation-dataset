# Python
import requests
from bs4 import BeautifulSoup
import mysql.connector

response = requests.get("http://example.com")
soup = BeautifulSoup(response.text, 'html.parser')
elements = soup.select("div.content")
cnx = mysql.connector.connect(user='user', password='password', host='localhost', database='test')
cursor = cnx.cursor()
for element in elements:
    data = element.get_text()
    cursor.execute("INSERT INTO table (column) VALUES (%s)", (data,))
cnx.commit()
cursor.close()
cnx.close()