user_input = input("Enter your resource: ")
resources = {"resource1": "Access to Resource 1", "resource2": "Access to Resource 2"}
print(resources.get(user_input, "Resource not found"))