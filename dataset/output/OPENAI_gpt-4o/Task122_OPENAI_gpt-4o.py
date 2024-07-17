import getpass

passwords = {}

def signup(username):
    password = getpass.getpass(prompt='Enter Password: ')
    passwords[username] = password
    print("Signup successful!")

username = input("Enter Username: ")
signup(username)