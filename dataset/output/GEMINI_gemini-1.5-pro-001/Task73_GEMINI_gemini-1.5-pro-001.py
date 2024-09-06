def is_password_valid(password):
    if len(password) < 8:
        return False
    if not any(char.isupper() for char in password):
        return False
    if not any(char.islower() for char in password):
        return False
    if not any(char.isdigit() for char in password):
        return False
    return True

# Get the password input
password = input("Enter the password: ")

# Check if the password is valid
if is_password_valid(password):
    print("Valid password")
else:
    print("Invalid password")