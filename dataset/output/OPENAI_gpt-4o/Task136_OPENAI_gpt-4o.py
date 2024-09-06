import getpass

def authenticate(username, password):
    stored_username = "user"
    stored_password = "pass"
    return username == stored_username and password == stored_password

username = input("Enter username: ")
password = getpass.getpass("Enter password: ")

if authenticate(username, password):
    print("Access granted")
else:
    print("Access denied")