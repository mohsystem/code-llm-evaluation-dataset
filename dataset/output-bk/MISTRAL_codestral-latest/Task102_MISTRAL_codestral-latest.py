# Python
import hashlib
import mysql.connector

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def update_password_in_database(username, hashed_password):
    conn = mysql.connector.connect(host="localhost", user="username", password="password", database="mydatabase")
    cursor = conn.cursor()
    cursor.execute("UPDATE users SET password = %s WHERE username = %s", (hashed_password, username))
    conn.commit()
    cursor.close()
    conn.close()

username = input("Enter username: ")
password = input("Enter new password: ")

hashed_password = hash_password(password)

update_password_in_database(username, hashed_password)