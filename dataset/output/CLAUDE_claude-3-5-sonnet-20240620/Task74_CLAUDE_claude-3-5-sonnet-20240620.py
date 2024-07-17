
import psycopg2

def get_connection():
    try:
        conn = psycopg2.connect(
            host="localhost",
            database="your_database",
            user="your_username",
            password="your_password"
        )
        return conn
    except psycopg2.Error as e:
        print(f"Error connecting to the database: {e}")
        return None

if __name__ == "__main__":
    conn = get_connection()
    if conn:
        print("Connected to the database!")
        conn.close()
    else:
        print("Failed to connect to the database.")
