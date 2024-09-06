class User:
    def __init__(self, username, password, privileges):
        self.username = username
        self.password = password
        self.privileges = privileges

    def has_privilege(self, privilege):
        return privilege in self.privileges

class PermissionManager:
    def __init__(self):
        self.users = {}

    def add_user(self, username, password, privileges):
        self.users[username] = User(username, password, privileges)

    def authenticate(self, username, password):
        if username in self.users and self.users[username].password == password:
            return self.users[username]
        else:
            return None

    def check_privilege(self, username, password, privilege):
        user = self.authenticate(username, password)
        if user and user.has_privilege(privilege):
            return True
        else:
            return False

# Example usage
manager = PermissionManager()
manager.add_user("admin", "password", ["read", "write", "execute"])
manager.add_user("user", "password", ["read"])

print(manager.check_privilege("admin", "password", "write"))  # True
print(manager.check_privilege("user", "password", "write"))  # False