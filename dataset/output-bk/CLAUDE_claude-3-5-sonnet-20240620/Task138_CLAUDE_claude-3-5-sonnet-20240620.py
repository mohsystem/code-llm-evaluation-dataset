
import json

class User:
    def __init__(self, username, role):
        self.username = username
        self.role = role
        self.permissions = []

class PermissionManager:
    def __init__(self):
        self.users = {}
        self.roles = {
            "admin": ["read", "write", "delete", "manage_users"],
            "editor": ["read", "write"],
            "viewer": ["read"]
        }

    def add_user(self, username, role):
        if role not in self.roles:
            raise ValueError("Invalid role")
        user = User(username, role)
        user.permissions = self.roles[role]
        self.users[username] = user

    def remove_user(self, username):
        if username in self.users:
            del self.users[username]

    def change_user_role(self, username, new_role):
        if username in self.users and new_role in self.roles:
            self.users[username].role = new_role
            self.users[username].permissions = self.roles[new_role]

    def check_permission(self, username, permission):
        if username in self.users:
            return permission in self.users[username].permissions
        return False

    def save_to_file(self, filename):
        data = {username: {"role": user.role, "permissions": user.permissions} 
                for username, user in self.users.items()}
        with open(filename, \'w\') as f:
            json.dump(data, f)

    def load_from_file(self, filename):
        with open(filename, \'r\') as f:
            data = json.load(f)
        for username, user_data in data.items():
            self.add_user(username, user_data["role"])

def main():
    pm = PermissionManager()

    pm.add_user("alice", "admin")
    pm.add_user("bob", "editor")
    pm.add_user("charlie", "viewer")

    print(pm.check_permission("alice", "manage_users"))  # True
    print(pm.check_permission("bob", "write"))  # True
    print(pm.check_permission("charlie", "delete"))  # False

    pm.change_user_role("bob", "admin")
    print(pm.check_permission("bob", "manage_users"))  # True

    pm.remove_user("charlie")
    print(pm.check_permission("charlie", "read"))  # False

    pm.save_to_file("permissions.json")
    new_pm = PermissionManager()
    new_pm.load_from_file("permissions.json")
    print(new_pm.check_permission("alice", "manage_users"))  # True

if __name__ == "__main__":
    main()
