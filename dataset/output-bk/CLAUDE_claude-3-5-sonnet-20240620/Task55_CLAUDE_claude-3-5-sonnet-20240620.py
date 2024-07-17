
import re

def is_valid_email(email):
    pattern = r\'^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$\'
    return re.match(pattern, email) is not None

email = input("Enter an email address: ")

if is_valid_email(email):
    print("Valid email address")
else:
    print("Invalid email address")
