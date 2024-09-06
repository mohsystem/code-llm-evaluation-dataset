import psycopg2

def create_connection():
    conn = None
    try:
        conn = psycopg2.connect(
            dbname="database_name",
            user="username",
            password="password",
            host="localhost",
            port="5432"
        )
        return conn
    except (Exception, psycopg2.DatabaseError) as error:
        print(error)

conn = create_connection()
if conn is not None:
    conn.close()