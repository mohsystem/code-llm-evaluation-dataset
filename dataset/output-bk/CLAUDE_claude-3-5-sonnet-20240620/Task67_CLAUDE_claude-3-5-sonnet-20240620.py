
import sys
import mysql.connector

if len(sys.argv) != 2:
    print("Please provide a customer username.")
    sys.exit(1)

customer_username = sys.argv[1]

try:
    conn = mysql.connector.connect(
        host="localhost",
        user="your_username",
        password="your_password",
        database="your_database"
    )

    cursor = conn.cursor(dictionary=True)

    query = "SELECT * FROM customer WHERE customerusername = %s"
    cursor.execute(query, (customer_username,))

    result = cursor.fetchone()

    if result:
        print(f"Customer ID: {result[\'customerid\']}")
        print(f"Name: {result[\'name\']}")
        print(f"Email: {result[\'email\']}")
        print(f"Phone: {result[\'phone\']}")
    else:
        print("Customer not found.")

except mysql.connector.Error as err:
    print(f"Error: {err}")

finally:
    if \'conn\' in locals() and conn.is_connected():
        cursor.close()
        conn.close()
