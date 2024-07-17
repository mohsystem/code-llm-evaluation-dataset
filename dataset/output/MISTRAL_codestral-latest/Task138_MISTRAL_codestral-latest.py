# Python
class User:
    def __init__(self, name, permissions):
        self.name = name
        self.permissions = permissions

    def has_permission(self, permission):
        return permission in self.permissions

# Example usage
user = User("John", ["read", "write"])
print(user.has_permission("read"))  # True
print(user.has_permission("execute"))  # False