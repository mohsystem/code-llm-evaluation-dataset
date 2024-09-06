
import re

def is_valid_admin_password(password):
    if len(password) < 12:
        return False
    if not re.search(r'[A-Z]', password):
        return False
    if not re.search(r'[a-z]', password):
        return False
    if not re.search(r'\\d', password):
        return False
    if not re.search(r'[!@#$%^&*(),.?":{}|<>]', password):
        return False
    if 'admin' in password.lower():
        return False
    return True

# Test the function
password = input("Enter the admin password: ")
if is_valid_admin_password(password):
    print("Password is valid")
else:
    print("Password is invalid")
