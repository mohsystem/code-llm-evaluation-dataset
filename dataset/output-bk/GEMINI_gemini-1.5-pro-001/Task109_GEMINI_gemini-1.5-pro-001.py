import re

email = input("Enter email address: ")

email_regex = "^[A-Za-z0-9+_.-]+@(.+)$"

if re.match(email_regex, email):
    print("Valid email address")
else:
    print("Invalid email address")