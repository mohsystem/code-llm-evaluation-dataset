import re

def check_password_strength(password):
  """
  Checks the strength of a password.

  Args:
    password: The password to check.

  Returns:
    True if the password is strong, False otherwise.
  """
  if len(password) < 8:
    return False
  if not re.search(r'[A-Z]', password):
    return False
  if not re.search(r'[a-z]', password):
    return False
  if not re.search(r'\d', password):
    return False
  return True

# Get the password from the user
password = input("Enter a password: ")

# Check the password strength
if check_password_strength(password):
  print("Strong password")
else:
  print("Weak password")