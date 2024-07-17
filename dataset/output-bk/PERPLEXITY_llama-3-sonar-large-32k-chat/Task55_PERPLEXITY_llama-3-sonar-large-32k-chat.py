import re

def validateEmail(email):
    emailRegex = re.compile(r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$")
    return bool(emailRegex.match(email))

email = input("Enter an email address:")
if validateEmail(email):
    print("Valid email address")
else:
    print("Invalid email address")