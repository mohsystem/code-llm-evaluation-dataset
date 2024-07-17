import hashlib

users = {}

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def register():
    username = input("Enter username: ")
    password = input("Enter password: ")
    users[username] = hash_password(password)
    print("User registered successfully!")

def login():
    username = input("Enter username: ")
    password = input("Enter password: ")
    
    if username in users and users[username] == hash_password(password):
        print("Login successful!")
    else:
        print("Invalid credentials.")

def main():
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

if __name__ == "__main__":
    main()