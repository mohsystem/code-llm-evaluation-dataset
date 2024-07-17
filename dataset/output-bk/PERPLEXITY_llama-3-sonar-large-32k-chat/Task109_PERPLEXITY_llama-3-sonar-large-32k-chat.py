import re

email = input("Enter your email:")
regex = r"^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$"
if re.match(regex, email):
    print("Email is valid")
else:
    print("Email is not valid")