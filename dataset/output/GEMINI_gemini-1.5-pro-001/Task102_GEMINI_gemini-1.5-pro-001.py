import hashlib
import sqlite3

def hash_password(password):
    """Hashes the given password using SHA-256."""
    return hashlib.sha256(password.encode()).hexdigest()

def update_password(username, new_password):
    """Updates the password for the given username in the database."""
    hashed_password = hash_password(new_password)
    try:
        conn = sqlite3.connect('users.db')
        cursor = conn.cursor()
        cursor.execute("UPDATE user SET password = ? WHERE username = ?", (hashed_password, username))
        conn.commit()
        print("Password updated successfully!")
    except sqlite3.Error as e:
        print(f"An error occurred: {e}")
    finally:
        conn.close()

if __name__ == "__main__":
    username = input("Enter username: ")
    new_password = input("Enter new password: ")
    update_password(username, new_password)