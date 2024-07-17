import re

def is_valid_admin_password(password):
    if len(password) < 10:
        return False
    if not re.search("[A-Z]", password):
        return False
    if not re.search("[a-z]", password):
        return False
    if not re.search("[0-9]", password):
        return False
    if not re.search("[!@#$%^&*()]", password):
        return False
    return True


password = input("Enter password: ")
if is_valid_admin_password(password):
    print("Valid password")
else:
    print("Invalid password")