# Python
import psycopg2

def create_db_connection():
    try:
        connection = psycopg2.connect(
            user = "your_username",
            password = "your_password",
            host = "localhost",
            port = "5432",
            database = "your_database"
        )
        return connection
    except (Exception, psycopg2.Error) as error :
        print ("Error while connecting to PostgreSQL", error)

# Call the function
conn = create_db_connection()