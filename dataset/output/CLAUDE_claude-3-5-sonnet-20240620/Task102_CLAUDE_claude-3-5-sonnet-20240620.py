
import hashlib
import sqlite3

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def update_password(username, new_password):
    hashed_password = hash_password(new_password)
    
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    
    cursor.execute('''CREATE TABLE IF NOT EXISTS users\n                      (username TEXT PRIMARY KEY, password TEXT)''')
    
    cursor.execute("UPDATE users SET password = ? WHERE username = ?", 
                   (hashed_password, username))
    
    if cursor.rowcount == 0:
        cursor.execute("INSERT INTO users (username, password) VALUES (?, ?)", 
                       (username, hashed_password))
    
    conn.commit()
    conn.close()

username = input("Enter username: ")
new_password = input("Enter new password: ")

update_password(username, new_password)
print("Password updated successfully.")
