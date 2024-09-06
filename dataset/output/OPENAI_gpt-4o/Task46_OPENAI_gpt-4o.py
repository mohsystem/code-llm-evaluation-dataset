import sqlite3

def create_table():
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        email TEXT NOT NULL,
        password TEXT NOT NULL
        );
    ''')
    conn.commit()
    conn.close()

def register_user(name, email, password):
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    cursor.execute('''
        INSERT INTO users (name, email, password) VALUES (?, ?, ?)
        ''', (name, email, password))
    conn.commit()
    conn.close()

create_table()
name = input("Enter your name: ")
email = input("Enter your email: ")
password = input("Enter your password: ")
register_user(name, email, password)
print("User registered successfully!")