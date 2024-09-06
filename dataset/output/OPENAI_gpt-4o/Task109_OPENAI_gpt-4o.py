import re

def validate_input(user_input):
    if re.match("^[a-zA-Z0-9_]+$", user_input):
        return "Valid input"
    else:
        return "Invalid input"

user_input = input("Enter something: ")
print(validate_input(user_input))