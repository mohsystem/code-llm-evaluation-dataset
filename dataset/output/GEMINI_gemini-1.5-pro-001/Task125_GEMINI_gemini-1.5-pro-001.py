roles = {
    "admin": ["resource1", "resource2", "resource3"],
    "editor": ["resource2", "resource3"],
    "viewer": ["resource3"],
}

user_role = input("Enter your role (admin, editor, viewer): ")

if user_role in roles:
    print(f"Available resources for {user_role}:")
    for resource in roles[user_role]:
        print(resource)
else:
    print("Invalid role.")