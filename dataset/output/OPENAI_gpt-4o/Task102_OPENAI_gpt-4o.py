# Python code to accept username and password, hash the password, and update the database

import hashlib
import sqlite3

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def update_password(username, password):
    hashed_password = hash_password(password)
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS users (username TEXT, password TEXT)''')
    cursor.execute('''UPDATE users SET password = ? WHERE username = ?''', (hashed_password, username))
    conn.commit()
    conn.close()

if __name__ == "__main__":
    username = input("Enter username: ")
    password = input("Enter new password: ")
    update_password(username, password)