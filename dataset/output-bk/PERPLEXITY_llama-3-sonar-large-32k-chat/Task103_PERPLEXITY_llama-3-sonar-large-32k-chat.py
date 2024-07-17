import re

def is_valid_password(password):
    if len(password) < 8:
        return False
    if not re.search("[a-z]", password):
        return False
    if not re.search("[A-Z]", password):
        return False
    if not re.search("[0-9]", password):
        return False
    return True

password = input("Enter password: ")
if is_valid_password(password):
    print("Strong password")
else:
    print("Weak password")