import psycopg2

def get_connection():
    try:
        conn = psycopg2.connect(
            host="localhost",
            port="5432",
            database="mydb",
            user="username",
            password="password"
        )
        return conn
    except psycopg2.Error as e:
        print(f"Connection to database failed: {e}")

if __name__ == "__main__":
    conn = get_connection()
    if conn:
        print("Connected to the database.")
        conn.close()