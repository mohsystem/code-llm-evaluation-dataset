import re

def is_valid_email(email):
    email_regex = r"^[a-zA-Z0-9_+&*-]+(?:\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\.)+[a-zA-Z]{2,7}$"
    return re.match(email_regex, email) is not None

if __name__ == "__main__":
    email = input("Enter an email address:
")
    if is_valid_email(email):
        print("Valid email address.")
    else:
        print("Invalid email address.")