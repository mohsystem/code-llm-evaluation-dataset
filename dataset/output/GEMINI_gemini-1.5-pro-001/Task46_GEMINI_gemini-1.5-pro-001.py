import sqlite3

def register_user(name, email, password):
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT NOT NULL UNIQUE,
            password TEXT NOT NULL
        )
    ''')
    try:
        cursor.execute("INSERT INTO users (name, email, password) VALUES (?, ?, ?)", (name, email, password))
        conn.commit()
        print("Registration successful!")
    except sqlite3.IntegrityError:
        print("Error: Email already exists.")
    finally:
        conn.close()

name = input("Enter your name: ")
email = input("Enter your email: ")
password = input("Enter your password: ")

register_user(name, email, password)