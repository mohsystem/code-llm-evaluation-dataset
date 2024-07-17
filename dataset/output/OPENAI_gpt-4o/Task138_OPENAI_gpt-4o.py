class User:
    def __init__(self, username):
        self.username = username
        self.permissions = set()

    def add_permission(self, permission):
        self.permissions.add(permission)

    def has_permission(self, permission):
        return permission in self.permissions

if __name__ == "__main__":
    user = User("john_doe")
    user.add_permission("read")
    user.add_permission("write")

    print(f"User {user.username} has read permission: {user.has_permission('read')}")
    print(f"User {user.username} has write permission: {user.has_permission('write')}")
    print(f"User {user.username} has delete permission: {user.has_permission('delete')}")