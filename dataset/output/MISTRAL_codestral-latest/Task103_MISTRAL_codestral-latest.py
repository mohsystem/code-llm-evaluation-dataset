def is_valid_password(password):
    if len(password) < 8:
        return False

    has_uppercase = False
    has_lowercase = False
    has_digit = False

    for c in password:
        if c.isupper():
            has_uppercase = True
        elif c.islower():
            has_lowercase = True
        elif c.isdigit():
            has_digit = True

    return has_uppercase and has_lowercase and has_digit

password = input("Enter a password: ")

if is_valid_password(password):
    print("Password is strong.")
else:
    print("Password is weak. It should be at least 8 characters long, contain both uppercase and lowercase letters, and contain at least one digit.")