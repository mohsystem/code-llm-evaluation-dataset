import psycopg2

def connect_to_database(host, database, user, password):
    try:
        conn = psycopg2.connect(
            host=host,
            database=database,
            user=user,
            password=password
        )
        return conn
    except Exception as e:
        print(f"Error connecting to database: {e}")
        return None

if __name__ == "__main__":
    conn = connect_to_database(
        host="localhost",
        database="your_database_name",
        user="your_username",
        password="your_password"
    )

    if conn:
        print("Connected to PostgreSQL database!")
        conn.close()