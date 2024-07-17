import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="username",
  password="password",
  database="mydb"
)

mycursor = mydb.cursor()

name = input("Enter name: ")
email = input("Enter email: ")
password = input("Enter password: ")

sql = "INSERT INTO users (name, email, password) VALUES (%s, %s, %s)"
val = (name, email, password)
mycursor.execute(sql, val)

mydb.commit()

print(mycursor.rowcount, "record inserted.")