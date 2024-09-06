
import hashlib
import os

def hash_password(password):
    salt = os.urandom(32)
    key = hashlib.pbkdf2_hmac('sha256', password.encode('utf-8'), salt, 100000)
    return salt + key

def signup():
    username = input("Enter username: ")
    password = input("Enter password: ")
    
    hashed_password = hash_password(password)
    
    with open("passwords.txt", "ab") as file:
        file.write(username.encode('utf-8') + b":" + hashed_password + b"\\n")
    
    print("Signup successful!")

if __name__ == "__main__":
    signup()
