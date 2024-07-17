
import sqlite3

def register_user():
    name = input("Enter your name: ")
    email = input("Enter your email: ")
    password = input("Enter your password: ")

    conn = sqlite3.connect(\'users.db\')
    cursor = conn.cursor()

    cursor.execute(\'\'\'
        CREATE TABLE IF NOT EXISTS users
        (name TEXT, email TEXT, password TEXT)
    \'\'\')

    cursor.execute(\'\'\'
        INSERT INTO users (name, email, password)
        VALUES (?, ?, ?)
    \'\'\', (name, email, password))

    conn.commit()
    conn.close()

    print("User registered successfully!")

if __name__ == "__main__":
    register_user()
