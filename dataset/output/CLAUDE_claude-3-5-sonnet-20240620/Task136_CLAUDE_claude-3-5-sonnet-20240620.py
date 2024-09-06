
import hashlib

users = {}

def register(username, password):
    if username in users:
        return False
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    users[username] = hashed_password
    return True

def login(username, password):
    if username not in users:
        return False
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    return users[username] == hashed_password

def main():
    while True:
        choice = input("1. Register\\n2. Login\\n3. Exit\\nChoose an option: ")
        if choice == '1':
            username = input("Enter username: ")
            password = input("Enter password: ")
            if register(username, password):
                print("Registration successful")
            else:
                print("Username already exists")
        elif choice == '2':
            username = input("Enter username: ")
            password = input("Enter password: ")
            if login(username, password):
                print("Login successful")
            else:
                print("Invalid credentials")
        elif choice == '3':
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
