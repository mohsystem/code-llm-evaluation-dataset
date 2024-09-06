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

    def has_permission(self, permission):
        return permission in self.permissions

def main():
    users = {}

    while True:
        action = input("Enter action (create user, add permission, remove permission, check permission, list users, exit): ")

        if action == "create user":
            username = input("Enter username: ")
            if username in users:
                print("User already exists.")
            else:
                users[username] = User(username)
                print("User created successfully.")

        elif action == "add permission":
            username = input("Enter username: ")
            if username in users:
                permission = input("Enter permission to add: ")
                users[username].add_permission(permission)
                print("Permission added successfully.")
            else:
                print("User not found.")

        elif action == "remove permission":
            username = input("Enter username: ")
            if username in users:
                permission = input("Enter permission to remove: ")
                users[username].remove_permission(permission)
                print("Permission removed successfully.")
            else:
                print("User not found.")

        elif action == "check permission":
            username = input("Enter username: ")
            if username in users:
                permission = input("Enter permission to check: ")
                if users[username].has_permission(permission):
                    print("User has permission.")
                else:
                    print("User does not have permission.")
            else:
                print("User not found.")

        elif action == "list users":
            if users:
                for username in users:
                    print(username)
            else:
                print("No users found.")

        elif action == "exit":
            break

        else:
            print("Invalid action.")

if __name__ == "__main__":
    main()