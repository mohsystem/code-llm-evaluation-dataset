def access_resource(resource):
    if resource == "admin":
        print("Access granted to admin resource")
    elif resource == "moderator":
        print("Access granted to moderator resource")
    elif resource == "user":
        print("Access granted to user resource")
    else:
        print("Access denied")

resource = input("Enter the resource you want to access: ")
access_resource(resource)