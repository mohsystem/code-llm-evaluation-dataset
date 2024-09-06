import sqlite3

def get_user_by_username(username):
    conn = sqlite3.connect('example.db')  # Change to your actual database
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM users WHERE username=?", (username,))
    user = cursor.fetchone()
    conn.close()
    return user

username = input("Enter username: ")
user = get_user_by_username(username)
print(user)