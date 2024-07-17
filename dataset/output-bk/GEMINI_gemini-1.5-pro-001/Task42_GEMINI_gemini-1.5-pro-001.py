import hashlib

users = {}

def register_user():
    username = input("Enter username: ")
    if username in users:
        print("Username already exists!")
        return
    password = input("Enter password: ")
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    users[username] = hashed_password
    print("User registered successfully!")

def login_user():
    username = input("Enter username: ")
    if username not in users:
        print("Invalid username or password!")
        return
    password = input("Enter password: ")
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    if hashed_password == users[username]:
        print("Login successful!")
    else:
        print("Invalid username or password!")

while True:
    print("1. Register")
    print("2. Login")
    print("3. Exit")
    choice = input("Enter your choice: ")

    if choice == '1':
        register_user()
    elif choice == '2':
        login_user()
    elif choice == '3':
        print("Exiting...")
        break
    else:
        print("Invalid choice!")