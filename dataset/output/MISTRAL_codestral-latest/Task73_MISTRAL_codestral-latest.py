def is_valid_password(password):
    # Admin password requirements:
    # - At least 8 characters long
    # - Contains at least one uppercase letter
    # - Contains at least one lowercase letter
    # - Contains at least one digit
    # - Contains at least one special character

    if len(password) < 8:
        return False
    if not any(char.isupper() for char in password):
        return False
    if not any(char.islower() for char in password):
        return False
    if not any(char.isdigit() for char in password):
        return False
    if not any(char in '!@#$%^&*()-_=+[]{}|;:,.<>?' for char in password):
        return False
    return True

# Test the function
password = input("Enter admin password: ")
if is_valid_password(password):
    print("Password is valid.")
else:
    print("Password is invalid.")