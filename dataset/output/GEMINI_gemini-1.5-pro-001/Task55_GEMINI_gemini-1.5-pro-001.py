import re

def is_valid_email(email):
  regex = r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
  match = re.match(regex, email)
  return bool(match)

email = input("Enter an email address: ")

if is_valid_email(email):
  print("Valid email address")
else:
  print("Invalid email address")