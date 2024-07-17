import psycopg2
from psycopg2 import OperationalError

def create_connection():
    connection = None
    try:
        connection = psycopg2.connect(
            database="mydatabase",
            user="myuser",
            password="mypassword",
            host="127.0.0.1",
            port="5432"
        )
        print("Python: Connection established successfully.")
    except OperationalError as e:
        print(f"Python: Connection failed: {e}")
    return connection

if __name__ == "__main__":
    conn = create_connection()
    if conn:
        conn.close()