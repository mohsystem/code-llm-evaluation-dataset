class User:
    def __init__(self, username):
        self.username = username
        self.permissions = set()
    
    def add_permission(self, permission):
        self.permissions.add(permission)
    
    def has_permission(self, permission):
        return permission in self.permissions

admin = User("admin")
admin.add_permission("read")
admin.add_permission("write")
print(f"Admin has 'read' permission: {admin.has_permission('read')}")
print(f"Admin has 'delete' permission: {admin.has_permission('delete')}")