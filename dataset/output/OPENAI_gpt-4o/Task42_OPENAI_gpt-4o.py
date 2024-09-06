import hashlib

class UserAuth:
    def __init__(self):
        self.users = {}

    def add_user(self, username, password):
        hashed = hashlib.sha256(password.encode()).hexdigest()
        self.users[username] = hashed

    def authenticate(self, username, password):
        hashed = hashlib.sha256(password.encode()).hexdigest()
        return self.users.get(username) == hashed

auth = UserAuth()
auth.add_user("user", "pass")
print(auth.authenticate("user", "pass"))
print(auth.authenticate("user", "wrongpass"))