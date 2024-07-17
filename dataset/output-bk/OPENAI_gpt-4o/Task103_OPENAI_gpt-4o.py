import sys

def is_valid_password(password):
    if len(password) < 8:
        return False
    has_upper = any(c.isupper() for c in password)
    has_lower = any(c.islower() for c in password)
    has_digit = any(c.isdigit() for c in password)
    return has_upper and has_lower and has_digit

if len(sys.argv) < 2:
    print("No password provided")
else:
    if is_valid_password(sys.argv[1]):
        print("Password is strong")
    else:
        print("Password is weak")