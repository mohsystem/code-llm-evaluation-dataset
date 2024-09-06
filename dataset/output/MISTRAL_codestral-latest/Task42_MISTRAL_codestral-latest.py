# Python
import getpass

# Dictionary to store user credentials
users = {"user1": "password1", "user2": "password2"}

def authenticate_user():
    username = input("Enter your username: ")
    password = getpass.getpass("Enter your password: ")

    if username in users and users[username] == password:
        print("Authentication successful.")
    else:
        print("Invalid username or password.")

authenticate_user()