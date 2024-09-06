import getpass

def check_password(stored_password):
  """Compares the user-entered password with the stored password.

  Args:
    stored_password: The password read from the file.

  Returns:
    True if passwords match, False otherwise.
  """
  entered_password = getpass.getpass("Enter password: ")
  if len(entered_password) != len(stored_password):
    return False
  for i in range(len(stored_password)):
    if stored_password[i] != entered_password[i]:
      return False
  return True

def main():
  """Main function to handle password comparison."""
  try:
    with open("password.txt", "r") as f:
      stored_password = f.read().strip()
  except FileNotFoundError:
    print("Password file not found. Please create 'password.txt'.")
    return

  if check_password(stored_password):
    print("Passwords match.")
  else:
    print("Passwords do not match.")

if __name__ == "__main__":
  main()