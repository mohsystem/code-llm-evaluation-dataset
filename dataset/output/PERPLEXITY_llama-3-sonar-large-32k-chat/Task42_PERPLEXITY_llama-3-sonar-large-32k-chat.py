code here:
class User:
    def __init__(self, username, password):
        self.username = username
        self.password = password

    def authenticate(self, username, password):
        if self.username == username and self.password == password:
            return True
        else:
            return False

def main():
    users = [User("user1", "password1"), User("user2", "password2")]
    username = input("Enter username: ")
    password = input("Enter password: ")
    for user in users:
        if user.authenticate(username, password):
            print("Authentication successful!")
            return
    print("Invalid credentials!")

if __name__ == "__main__":
    main()