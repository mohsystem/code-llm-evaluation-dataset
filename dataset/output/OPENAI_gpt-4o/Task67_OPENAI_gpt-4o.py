import sqlite3
import sys

def get_customer_info(username):
    conn = sqlite3.connect('your_database.db')
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM customer WHERE username = ?", (username,))
    customer = cursor.fetchone()
    conn.close()
    return customer

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <customerusername>")
        sys.exit(1)
    customer_username = sys.argv[1]
    customer_info = get_customer_info(customer_username)
    print(customer_info)