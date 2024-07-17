import getpass
import hashlib
import mysql.connector

def hash_password(password):
    # Simple hashing example, in real-world scenarios use a secure hashing algorithm like bcrypt
    return hashlib.sha256(password.encode()).hexdigest()

username = input("Enter username: ")
password = getpass.getpass("Enter new password: ")
hashed_password = hash_password(password)

cnx = mysql.connector.connect(user='root', password='password',
                              host='127.0.0.1',
                              database='mydb')
cursor = cnx.cursor()

query = "UPDATE users SET password = %s WHERE username = %s"
cursor.execute(query, (hashed_password, username))

cnx.commit()
print("Password updated successfully!")

cursor.close()
cnx.close()