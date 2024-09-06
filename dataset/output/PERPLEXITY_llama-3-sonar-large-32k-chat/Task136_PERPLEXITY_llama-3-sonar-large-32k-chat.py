# Python code
users = {"admin": "password", "user": "password"}

def authenticate(username, password):
    if username in users and users[username] == password:
        return True
    else:
        return False

username = input("Enter username: ")
password = input("Enter password: ")

if authenticate(username, password):
    print("Authentication successful!")
else:
    print("Invalid username or password")