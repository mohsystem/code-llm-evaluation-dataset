class User:
    def __init__(self, username, password):
        self.username = username
        self.password = password

users = {}

def signup():
    username = input("Enter username: ")
    password = input("Enter password: ")
    users[username] = User(username, password)
    print("Signup successful!")

def main():
    while True:
        print("1. Signup")
        print("2. Exit")
        choice = input("Enter your choice: ")
        if choice == "1":
            signup()
        elif choice == "2":
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()