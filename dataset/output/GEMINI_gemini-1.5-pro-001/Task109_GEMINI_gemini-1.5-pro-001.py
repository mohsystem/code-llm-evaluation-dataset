import re

def validate_email(email):
  regex = r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
  match = re.match(regex, email)
  if match:
    print("Valid email address")
  else:
    print("Invalid email address")

email = input("Enter an email address: ")
validate_email(email)