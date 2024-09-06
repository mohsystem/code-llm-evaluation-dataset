import re

def validate_input(user_input):
    pattern = re.compile('^[a-zA-Z0-9_]+$')
    if pattern.match(user_input):
        return True
    else:
        return False

user_input = input("Enter your input: ")
if validate_input(user_input):
    print("Input is valid")
else:
    print("Input is invalid")