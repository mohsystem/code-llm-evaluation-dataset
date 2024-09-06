def password_strength(password):
    if len(password) < 8:
        return False
    if not any(char.isupper() for char in password):
        return False
    if not any(char.islower() for char in password):
        return False
    if not any(char.isdigit() for char in password):
        return False
    return True

password = input("Enter a password: ")
if password_strength(password):
    print("Strong password")
else:
    print("Weak password")