
import hashlib
import getpass

class UserAuthentication:
    def __init__(self):
        self.users = {}

    def register(self):
        username = input("Enter username: ")
        if username in self.users:
            print("Username already exists. Please choose another.")
            return

        password = getpass.getpass("Enter password: ")
        hashed_password = self.hash_password(password)
        self.users[username] = hashed_password
        print("Registration successful.")

    def login(self):
        username = input("Enter username: ")
        password = getpass.getpass("Enter password: ")
        hashed_password = self.hash_password(password)

        if username in self.users and self.users[username] == hashed_password:
            print("Login successful.")
        else:
            print("Invalid username or password.")

    @staticmethod
    def hash_password(password):
        return hashlib.sha256(password.encode()).hexdigest()

def main():
    auth = UserAuthentication()

    while True:
        print("1. Register")
        print("2. Login")
        print("3. Exit")
        choice = input("Choose an option: ")

        if choice == "1":
            auth.register()
        elif choice == "2":
            auth.login()
        elif choice == "3":
            print("Goodbye!")
            break
        else:
            print("Invalid option. Please try again.")

if __name__ == "__main__":
    main()
