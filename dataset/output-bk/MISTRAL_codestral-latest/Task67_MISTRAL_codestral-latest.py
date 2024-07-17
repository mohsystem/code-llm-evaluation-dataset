# Python
import mysql.connector
import sys

mydb = mysql.connector.connect(
  host="localhost",
  user="username",
  password="password",
  database="myDatabase"
)

mycursor = mydb.cursor()

mycursor.execute("SELECT * FROM customer WHERE username = %s", (sys.argv[1],))

myresult = mycursor.fetchall()

for x in myresult:
  print(x)