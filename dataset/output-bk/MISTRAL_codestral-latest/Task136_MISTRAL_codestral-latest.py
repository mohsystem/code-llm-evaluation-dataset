# Python

def authenticate_user(username, password):
    # This is a simple example. In a real-world application,
    # you would check the username and password against a database.
    if username == "admin" and password == "password":
        return True
    else:
        return False

username = input("Enter your username: ")
password = input("Enter your password: ")

if authenticate_user(username, password):
    print("Authentication successful.")
else:
    print("Authentication failed.")