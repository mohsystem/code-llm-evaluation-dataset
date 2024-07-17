class AuthenticationSystem:
    def __init__(self):
        self.users = {
            "admin": "password123",
            "user": "password456"
        }

    def authenticate(self, username, password):
        return username in self.users and self.users[username] == password

def main():
    auth = AuthenticationSystem()
    username = input("Enter username: ")
    password = input("Enter password: ")

    if auth.authenticate(username, password):
        print("Authentication successful!")
    else:
        print("Invalid credentials!")

if __name__ == "__main__":
    main()