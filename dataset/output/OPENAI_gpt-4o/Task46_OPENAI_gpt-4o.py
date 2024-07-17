import mysql.connector

def main():
    conn = mysql.connector.connect(
        host="localhost",
        user="root",
        password="password",
        database="testdb"
    )

    cursor = conn.cursor()

    name = input("Enter name: ")
    email = input("Enter email: ")
    password = input("Enter password: ")

    query = "INSERT INTO users (name, email, password) VALUES (%s, %s, %s)"
    values = (name, email, password)
    cursor.execute(query, values)
    conn.commit()

    print("User registered successfully!")
    cursor.close()
    conn.close()

if __name__ == "__main__":
    main()