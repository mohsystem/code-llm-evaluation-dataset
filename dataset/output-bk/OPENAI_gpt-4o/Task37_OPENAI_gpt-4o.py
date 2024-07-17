import mysql.connector

def main():
    username = input("Enter username: ")

    conn = mysql.connector.connect(
        host='localhost',
        user='yourusername',
        password='yourpassword',
        database='yourdatabasename'
    )

    cursor = conn.cursor()
    query = "SELECT * FROM users WHERE username = %s"
    cursor.execute(query, (username,))
    
    for (user, email) in cursor:
        print(f"Username: {user}")
        print(f"Email: {email}")

    cursor.close()
    conn.close()

if __name__ == "__main__":
    main()