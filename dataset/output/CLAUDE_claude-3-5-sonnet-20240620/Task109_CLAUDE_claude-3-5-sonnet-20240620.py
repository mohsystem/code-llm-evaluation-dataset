
import re

def validate_input():
    # Email validation
    email_pattern = r'^[\\w\\.-]+@[\\w\\.-]+\\.\\w+$'
    email = input("Enter your email: ")
    if re.match(email_pattern, email):
        print("Valid email")
    else:
        print("Invalid email")

    # Phone number validation (US format)
    phone_pattern = r'^\\(?([0-9]{3})\\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$'
    phone = input("Enter your phone number: ")
    if re.match(phone_pattern, phone):
        print("Valid phone number")
    else:
        print("Invalid phone number")

    # Password validation (at least 8 characters, 1 uppercase, 1 lowercase, 1 digit)
    password_pattern = r'^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$'
    password = input("Enter your password: ")
    if re.match(password_pattern, password):
        print("Valid password")
    else:
        print("Invalid password")

if __name__ == "__main__":
    validate_input()
