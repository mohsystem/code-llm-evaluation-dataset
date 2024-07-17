import hashlib
import mysql.connector

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def update_password(username, hashed_password):
    try:
        mydb = mysql.connector.connect(
            host="localhost",
            user="your_database_user",
            password="your_database_password",
            database="your_database_name"
        )
        cursor = mydb.cursor()
        sql = "UPDATE users SET password = %s WHERE username = %s"
        val = (hashed_password, username)
        cursor.execute(sql, val)
        mydb.commit()
        print("Password updated successfully.")
    except Exception as e:
        print(f"Error updating password: {e}")
    finally:
        if mydb.is_connected():
            cursor.close()
            mydb.close()

if __name__ == "__main__":
    username = input("Enter username: ")
    new_password = input("Enter new password: ")
    hashed_password = hash_password(new_password)
    update_password(username, hashed_password)