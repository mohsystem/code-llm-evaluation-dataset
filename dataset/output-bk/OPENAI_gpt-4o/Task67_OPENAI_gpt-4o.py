import mysql.connector
import sys

def main(username):
    conn = mysql.connector.connect(
        host="localhost",
        user="root",
        password="password",
        database="yourdb"
    )
    cursor = conn.cursor()
    query = "SELECT * FROM customer WHERE username = %s"
    cursor.execute(query, (username,))
    result = cursor.fetchone()

    if result:
        print(f"ID: {result[0]}")
        print(f"Username: {result[1]}")
        print(f"Name: {result[2]}")
        print(f"Email: {result[3]}")
    else:
        print("No customer found with that username.")

    cursor.close()
    conn.close()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <customerusername>")
    else:
        main(sys.argv[1])