# Python code using sqlite3 for database operations and hashlib for password hashing
import sqlite3
import hashlib

def update_password(username, new_password):
    # Connect to the SQLite database
    conn = sqlite3.connect('user_database.db')
    c = conn.cursor()

    # Hash the new password
    hashed_password = hashlib.sha256(new_password.encode()).hexdigest()

    # Update the password in the database
    c.execute("UPDATE users SET password = ? WHERE username = ?", (hashed_password, username))
    conn.commit()
    conn.close()

# Accept username and new password from user
username = input("Enter your username: ")
new_password = input("Enter your new password: ")

# Update the password
update_password(username, new_password)