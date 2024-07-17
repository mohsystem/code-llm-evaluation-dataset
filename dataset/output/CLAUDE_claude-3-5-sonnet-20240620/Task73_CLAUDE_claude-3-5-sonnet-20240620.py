
import re

def is_valid_password(password):
    if len(password) < 12:
        return False
    if not re.search(r\'[A-Z]\', password):
        return False
    if not re.search(r\'[a-z]\', password):
        return False
    if not re.search(r\'\\d\', password):
        return False
    if not re.search(r\'[!@#$%^&*()_+\\-=\\[\\]{};:\\\'"\\\\|,.<>\\/?]\', password):
        return False
    return True

password = input("Enter password: ")

if is_valid_password(password):
    print("Password is valid.")
else:
    print("Password is invalid.")
