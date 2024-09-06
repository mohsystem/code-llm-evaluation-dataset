
import psycopg2

def create_connection():
    try:
        conn = psycopg2.connect(
            host="localhost",
            database="your_database",
            user="your_username",
            password="your_password"
        )
        return conn
    except (Exception, psycopg2.Error) as error:
        print("Error while connecting to PostgreSQL", error)
        return None

# Usage
connection = create_connection()
if connection:
    print("Connection created successfully")
    connection.close()
