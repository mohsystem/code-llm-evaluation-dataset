import sys
import mysql.connector

def get_customer_info(username):
    db = mysql.connector.connect(
        host="localhost",
        user="your_username",
        password="your_password",
        database="your_database"
    )
    cursor = db.cursor()
    query = "SELECT * FROM customer WHERE customerusername = %s"
    cursor.execute(query, (username,))
    result = cursor.fetchone()
    db.close()
    return result

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <customer_username>")
        sys.exit(1)
    username = sys.argv[1]
    customer_info = get_customer_info(username)
    if customer_info:
        print(customer_info)
    else:
        print("Customer not found")