
import json

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
        self.users[username] = role

    def remove_user(self, username):
        if username in self.users:
            del self.users[username]

    def change_user_role(self, username, new_role):
        if username not in self.users:
            raise ValueError("User not found")
        if new_role not in self.roles:
            raise ValueError("Invalid role")
        self.users[username] = new_role

    def check_permission(self, username, permission):
        if username not in self.users:
            return False
        user_role = self.users[username]
        return permission in self.roles[user_role]

    def save_to_file(self, filename):
        with open(filename, 'w') as f:
            json.dump(self.users, f)

    def load_from_file(self, filename):
        with open(filename, 'r') as f:
            self.users = json.load(f)

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
    pm.load_from_file("permissions.json")

if __name__ == "__main__":
    main()
