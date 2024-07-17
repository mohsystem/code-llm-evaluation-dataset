import mysql.connector
import sys

class Customer:
    def __init__(self, username, name, email):
        self.username = username
        self.name = name
        self.email = email

    def __str__(self):
        return f"Customer: username={self.username}, name={self.name}, email={self.email}"

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} <customerusername>")
        sys.exit(1)

    customer_username = sys.argv[1]

    conn = mysql.connector.connect(
        user='root',
        password='password',
        host='localhost',
        database='mydb'
    )

    cursor = conn.cursor()
    query = "SELECT * FROM customer WHERE username = %s"
    cursor.execute(query, (customer_username,))

    row = cursor.fetchone()
    if row:
        customer = Customer(*row)
        print(customer)
    else:
        print("Customer not found")

    cursor.close()
    conn.close()