
import mysql.connector
from mysql.connector import Error

try:
    connection = mysql.connector.connect(
        host=\'localhost\',
        database=\'your_database\',
        user=\'your_username\',
        password=\'your_password\'
    )

    if connection.is_connected():
        username = input("Enter username: ")

        cursor = connection.cursor(prepared=True)
        query = "SELECT * FROM users WHERE username = %s"
        cursor.execute(query, (username,))

        result = cursor.fetchone()

        if result:
            print(f"User ID: {result[0]}")
            print(f"Username: {result[1]}")
            print(f"Email: {result[2]}")
        else:
            print("User not found.")

        cursor.close()

except Error as e:
    print(f"Error: {e}")

finally:
    if connection.is_connected():
        connection.close()
