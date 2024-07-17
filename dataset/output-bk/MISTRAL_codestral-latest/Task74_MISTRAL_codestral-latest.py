# Python
import psycopg2
from psycopg2 import Error

def getConnection():
    try:
        connection = psycopg2.connect(
            user="postgres",
            password="password",
            host="localhost",
            database="test"
        )
        return connection
    except (Exception, Error) as error:
        print("Error while connecting to PostgreSQL", error)