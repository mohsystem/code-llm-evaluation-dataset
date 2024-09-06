import psycopg2

def connect_to_postgres(host, database, user, password):
    """Creates and returns a connection object to a PostgreSQL database.

    Args:
        host (str): The hostname or IP address of the database server.
        database (str): The name of the database.
        user (str): The username to connect with.
        password (str): The password for the user.

    Returns:
        connection: A connection object to the database.
    """
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