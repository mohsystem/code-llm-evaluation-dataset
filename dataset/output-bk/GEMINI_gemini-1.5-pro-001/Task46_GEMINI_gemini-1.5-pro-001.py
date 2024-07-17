import mysql.connector

def register_user():
    name = input("Enter your name: ")
    email = input("Enter your email: ")
    password = input("Enter your password: ")

    try:
        mydb = mysql.connector.connect(
            host="localhost",
            user="username",
            password="password",
            database="user_db"
        )

        cursor = mydb.cursor()
        sql = "INSERT INTO users (name, email, password) VALUES (%s, %s, %s)"
        values = (name, email, password)
        cursor.execute(sql, values)
        mydb.commit()

        print("Registration successful!")

    except mysql.connector.Error as err:
        print("Error: ", err)

    finally:
        if mydb.is_connected():
            cursor.close()
            mydb.close()

register_user()