# Python
def validate_input(user_input):
    # Add your validation logic here
    return True

def perform_operations(user_input):
    # Add your operations here
    print("Performing operations on:", user_input)

user_input = input("Enter something: ")
if validate_input(user_input):
    perform_operations(user_input)
else:
    print("Invalid input")