# Python code using sqlite3 for database operations
import sqlite3

# Connect to SQLite database
conn = sqlite3.connect('user_database.db')
c = conn.cursor()

# Create table
c.execute('''CREATE TABLE IF NOT EXISTS users
             (name TEXT, email TEXT, password TEXT)''')

# Function to register a new user
def register_user(name, email, password):
    c.execute("INSERT INTO users VALUES (?, ?, ?)", (name, email, password))
    conn.commit()

# Test the function
register_user('John Doe', 'johndoe@example.com', 'password123')