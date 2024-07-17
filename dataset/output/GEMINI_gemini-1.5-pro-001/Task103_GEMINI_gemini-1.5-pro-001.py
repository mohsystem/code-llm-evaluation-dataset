import re

def check_password_strength(password):
    if len(password) < 8:
        print("Password must be at least 8 characters long.")
        return

    if not re.search(r"[A-Z]", password):
        print("Password must contain at least one uppercase letter.")
        return

    if not re.search(r"[a-z]", password):
        print("Password must contain at least one lowercase letter.")
        return

    if not re.search(r"\d", password):
        print("Password must contain at least one digit.")
        return

    print("Strong password.")

password = input("Enter password: ")
check_password_strength(password)