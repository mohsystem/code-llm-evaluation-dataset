import re

def validate_input():
    pattern = r"^[a-zA-Z0-9_]{3,16}$"
    user_input = input("Enter a username: ")
    if re.match(pattern, user_input):
        print("Valid username")
    else:
        print("Invalid username")

validate_input()