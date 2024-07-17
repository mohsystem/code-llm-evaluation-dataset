import mysql.connector

def main():
    username = input("Enter username: ")

    db = mysql.connector.connect(
        host="localhost",
        user="root",
        password="password",
        database="mydb"
    )

    cursor = db.cursor()
    query = "SELECT * FROM users WHERE username = %s"
    cursor.execute(query, (username,))

    for row in cursor.fetchall():
        print("Username:", row[0])
        print("Email:", row[1])
        print("Password:", row[2])

    cursor.close()
    db.close()

if __name__ == "__main__":
    main()