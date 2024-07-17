# Python
import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="username",
  password="password",
  database="myDatabase"
)

mycursor = mydb.cursor()

username = input("Enter username: ")

query = "SELECT * FROM Users WHERE username = %s"
mycursor.execute(query, (username,))

myresult = mycursor.fetchall()

for x in myresult:
  print(x)