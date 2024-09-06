# Python

class User:
    def __init__(self, username, password):
        self.username = username
        self.password = password

class Authentication:
    def __init__(self):
        self.users = []

    def register(self, username, password):
        new_user = User(username, password)
        self.users.append(new_user)
        print("User registered successfully.")

    def login(self, username, password):
        for user in self.users:
            if user.username == username and user.password == password:
                print("Login successful.")
                return
        print("Invalid username or password.")

auth = Authentication()
auth.register("user1", "password1")
auth.login("user1", "password1")