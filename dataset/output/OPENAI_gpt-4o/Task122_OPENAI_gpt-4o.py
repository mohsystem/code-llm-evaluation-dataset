class User:
    def __init__(self, username, password):
        self.username = username
        self.password = password

database = []

def signup(username, password):
    database.append(User(username, password))
    print("User signed up successfully")

username = input("Enter username: ")
password = input("Enter password: ")
signup(username, password)