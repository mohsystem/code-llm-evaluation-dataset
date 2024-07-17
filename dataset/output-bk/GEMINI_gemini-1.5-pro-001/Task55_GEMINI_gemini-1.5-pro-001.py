import re

def isValidEmail(email):
    regex = "^[A-Za-z0-9+_.-]+@(.+)$"
    match = re.match(regex, email)
    return bool(match)

email = "user@example.com"
if isValidEmail(email):
    print("Valid Email")
else:
    print("Invalid Email")