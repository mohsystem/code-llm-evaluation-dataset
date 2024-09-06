import hashlib

def hash_password(password):
  """Hashes the password using SHA-256."""
  return hashlib.sha256(password.encode()).hexdigest()

def create_user(username, password):
  """Creates a new user with hashed password."""
  hashed_password = hash_password(password)
  with open("users.txt", "a") as f:
    f.write(f"{username}:{hashed_password}\n")
  print(f"User '{username}' created successfully!")

def authenticate_user(username, password):
  """Authenticates user based on stored credentials."""
  hashed_password = hash_password(password)
  with open("users.txt", "r") as f:
    for line in f:
      u, h = line.strip().split(":")
      if u == username and h == hashed_password:
        print("Authentication successful. Welcome!")
        return True
  print("Authentication failed. Invalid username or password.")
  return False

while True:
  choice = input("1. Create user\n2. Login\n3. Exit\nChoose an option: ")
  if choice == "1":
    username = input("Enter username: ")
    password = input("Enter password: ")
    create_user(username, password)
  elif choice == "2":
    username = input("Enter username: ")
    password = input("Enter password: ")
    authenticate_user(username, password)
  elif choice == "3":
    break
  else:
    print("Invalid choice.")