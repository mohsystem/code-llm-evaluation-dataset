import sys
import mysql.connector

def main():
    if len(sys.argv) != 2:
        print("Usage: python get_customer_info.py <customerusername>")
        return

    customer_username = sys.argv[1]

    db_config = {
        "host": "localhost",
        "user": "your_username",
        "password": "your_password",
        "database": "your_database_name"
    }

    try:
        conn = mysql.connector.connect(**db_config)
        cursor = conn.cursor(dictionary=True)

        query = "SELECT * FROM customer WHERE customerusername = %s"
        cursor.execute(query, (customer_username,))
        customer = cursor.fetchone()

        if customer:
            print("Customer Information:")
            print(f"Username: {customer['customerusername']}")
            print(f"First Name: {customer['firstname']}")
            print(f"Last Name: {customer['lastname']}")
            print(f"Email: {customer['email']}")
        else:
            print("Customer not found.")

        cursor.close()
        conn.close()

    except mysql.connector.Error as err:
        print(f"Error: {err}")

if __name__ == "__main__":
    main()