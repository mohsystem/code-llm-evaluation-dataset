import re

def is_valid_password(password):
  """
  Checks if a password meets the following criteria:
    - At least 8 characters long
    - Contains at least one uppercase letter
    - Contains at least one lowercase letter
    - Contains at least one digit
  """
  if len(password) < 8:
    return False
  if not re.search("[a-z]", password):
    return False
  if not re.search("[A-Z]", password):
    return False
  if not re.search("[0-9]", password):
    return False
  return True

def reset_password():
  """
  Prompts the user to enter a new password twice and updates it if it's valid.
  """
  while True:
    new_password = input("Enter your new password: ")
    confirm_password = input("Confirm your new password: ")
    if new_password == confirm_password and is_valid_password(new_password):
      print("Password reset successfully!")
      break
    else:
      print("Invalid password or passwords don't match. Please try again.")

if __name__ == "__main__":
  reset_password()