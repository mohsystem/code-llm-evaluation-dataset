import sqlite3

def create_table():
    conn = sqlite3.connect('users.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS users
                 (name TEXT, email TEXT PRIMARY KEY, password TEXT)''')
    conn.commit()
    conn.close()

def register_user(name, email, password):
    conn = sqlite3.connect('users.db')
    c = conn.cursor()
    c.execute("INSERT INTO users VALUES (?, ?, ?)", (name, email, password))
    conn.commit()
    conn.close()

def main():
    create_table()
    name = input("Enter your name: ")
    email = input("Enter your email: ")
    password = input("Enter your password: ")
    register_user(name, email, password)
    print("User registered successfully!")

if __name__ == "__main__":
    main()