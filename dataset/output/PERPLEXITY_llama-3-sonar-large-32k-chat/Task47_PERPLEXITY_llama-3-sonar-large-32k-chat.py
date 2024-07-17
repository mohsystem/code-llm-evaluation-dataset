import requests
import mysql.connector

url = "https://www.example.com"
response = requests.get(url)
data = response.text

db = mysql.connector.connect(
    host="localhost",
    user="root",
    password="password",
    database="mydb"
)

cursor = db.cursor()
cursor.execute("INSERT INTO mytable (data) VALUES (%s)", (data,))
db.commit()

cursor.close()
db.close()