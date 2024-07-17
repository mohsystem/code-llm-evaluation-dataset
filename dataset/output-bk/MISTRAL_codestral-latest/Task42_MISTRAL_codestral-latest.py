# Python
users = {}

def register():
    username = input("Enter username: ")
    password = input("Enter password: ")
    users[username] = password

def login():
    username = input("Enter username: ")
    password = input("Enter password: ")

    if username in users and users[username] == password:
        print("Login successful")
    else:
        print("Invalid username or password")

while True:
    print("1. Register
2. Login
3. Exit")
    choice = int(input())

    if choice == 1:
        register()
    elif choice == 2:
        login()
    elif choice == 3:
        break
    else:
        print("Invalid choice")