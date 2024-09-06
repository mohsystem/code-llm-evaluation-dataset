
import sqlite3

def create_table():
    conn = sqlite3.connect('users.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS users\n                 (name TEXT, email TEXT PRIMARY KEY, password TEXT)''')
    conn.commit()
    conn.close()

def register_user():
    name = input("Enter your name: ")
    email = input("Enter your email: ")
    password = input("Enter your password: ")

    conn = sqlite3.connect('users.db')
    c = conn.cursor()
    try:
        c.execute("INSERT INTO users VALUES (?, ?, ?)", (name, email, password))
        conn.commit()
        print("Registration successful!")
    except sqlite3.IntegrityError:
        print("Email already exists. Registration failed.")
    finally:
        conn.close()

if __name__ == "__main__":
    create_table()
    register_user()
