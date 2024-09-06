import sqlite3

conn = sqlite3.connect('your_database.db')
cursor = conn.cursor()

username = input("Enter username: ")

cursor.execute("SELECT * FROM users WHERE username=?", (username,))
user = cursor.fetchone()

if user:
    print(user)
else:
    print("User not found.")

conn.close()