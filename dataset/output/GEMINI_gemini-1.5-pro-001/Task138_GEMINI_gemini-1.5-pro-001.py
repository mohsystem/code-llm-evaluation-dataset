class Permission:
    def __init__(self, name):
        self.name = name

class User:
    def __init__(self, username):
        self.username = username
        self.permissions = []

    def add_permission(self, permission):
        if permission not in self.permissions:
            self.permissions.append(permission)

    def remove_permission(self, permission):
        if permission in self.permissions:
            self.permissions.remove(permission)

    def has_permission(self, permission_name):
        return any(p.name == permission_name for p in self.permissions)

# Example usage:
read_permission = Permission("read")
write_permission = Permission("write")

user1 = User("john_doe")
user1.add_permission(read_permission)

user2 = User("jane_doe")
user2.add_permission(read_permission)
user2.add_permission(write_permission)

print(f"{user1.username} has read permission: {user1.has_permission('read')}")
print(f"{user1.username} has write permission: {user1.has_permission('write')}")

print(f"{user2.username} has read permission: {user2.has_permission('read')}")
print(f"{user2.username} has write permission: {user2.has_permission('write')}")