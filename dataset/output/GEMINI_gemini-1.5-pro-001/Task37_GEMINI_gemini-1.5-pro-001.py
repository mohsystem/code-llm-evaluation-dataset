import mysql.connector

try:
    connection = mysql.connector.connect(
        host="localhost",
        user="your_username",
        password="your_password",
        database="your_database_name"
    )
    cursor = connection.cursor()

    username = input("Enter username: ")

    query = "SELECT * FROM users WHERE username = %s"
    cursor.execute(query, (username,))

    result = cursor.fetchall()
    for row in result:
        print("Username:", row[0])
        print("Email:", row[1])
        # Retrieve other user information as needed

except mysql.connector.Error as error:
    print("Error connecting to database or executing query:", error)

finally:
    if connection.is_connected():
        cursor.close()
        connection.close()