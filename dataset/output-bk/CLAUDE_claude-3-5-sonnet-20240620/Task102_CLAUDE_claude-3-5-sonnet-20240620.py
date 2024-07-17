
import hashlib
import mysql.connector

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def update_password_in_database(username, hashed_password):
    try:
        conn = mysql.connector.connect(
            host="localhost",
            user="your_username",
            password="your_password",
            database="your_database"
        )
        cursor = conn.cursor()

        sql = "UPDATE users SET password = %s WHERE username = %s"
        values = (hashed_password, username)
        cursor.execute(sql, values)

        conn.commit()

        if cursor.rowcount > 0:
            print("Password updated successfully.")
        else:
            print("User not found.")

    except mysql.connector.Error as err:
        print(f"Error: {err}")

    finally:
        if conn.is_connected():
            cursor.close()
            conn.close()

def main():
    username = input("Enter username: ")
    password = input("Enter new password: ")

    hashed_password = hash_password(password)
    update_password_in_database(username, hashed_password)

if __name__ == "__main__":
    main()
