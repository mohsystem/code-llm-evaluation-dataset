
import sys
import sqlite3

def get_customer_info(username):
    conn = sqlite3.connect('customer_database.db')
    cursor = conn.cursor()
    
    cursor.execute("SELECT * FROM customer WHERE customerusername = ?", (username,))
    customer = cursor.fetchone()
    
    conn.close()
    
    if customer:
        return {
            "id": customer[0],
            "username": customer[1],
            "name": customer[2],
            "email": customer[3],
            "phone": customer[4]
        }
    else:
        return None

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <customerusername>")
        sys.exit(1)
    
    username = sys.argv[1]
    customer_info = get_customer_info(username)
    
    if customer_info:
        print("Customer Information:")
        for key, value in customer_info.items():
            print(f"{key}: {value}")
    else:
        print("Customer not found.")
