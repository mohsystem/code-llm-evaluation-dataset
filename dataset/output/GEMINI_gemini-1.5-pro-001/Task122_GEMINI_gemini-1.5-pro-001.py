import hashlib

def signup():
  username = input("Enter username: ")
  password = input("Enter password: ")
  hashed_password = hashlib.sha256(password.encode()).hexdigest()
  with open("users.txt", "a") as f:
    f.write(f"{username}:{hashed_password}\n")
  print("Signup successful!")

while True:
  choice = input("1. Signup\n2. Exit\nEnter choice: ")
  if choice == "1":
    signup()
  elif choice == "2":
    break
  else:
    print("Invalid choice!")