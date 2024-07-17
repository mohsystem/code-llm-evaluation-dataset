
import hashlib
import json

passwords = {}

def signup():
    username = input("Enter username: ")
    password = input("Enter password: ")
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    passwords[username] = hashed_password
    with open(\'passwords.json\', \'w\') as f:
        json.dump(passwords, f)
    print("Signup successful!")

while True:
    signup()
    if input("Do you want to add another user? (y/n): ").lower() != \'y\':
        break

print("Final password dictionary:", passwords)
