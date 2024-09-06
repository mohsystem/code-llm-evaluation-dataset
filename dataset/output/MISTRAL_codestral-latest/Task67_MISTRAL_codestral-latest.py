import sys
import sqlite3

def get_customer_info(customerusername):
    conn = sqlite3.connect('database.db')
    cursor = conn.cursor()
    query = "SELECT * FROM customer WHERE customerusername = ?"
    cursor.execute(query, (customerusername,))
    customer_info = cursor.fetchone()
    conn.close()
    return customer_info

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <customerusername>")
        sys.exit(1)

    customerusername = sys.argv[1]
    customer_info = get_customer_info(customerusername)

    if customer_info:
        print(f"Customer Info: {customer_info}")
    else:
        print(f"No customer found with username: {customerusername}")