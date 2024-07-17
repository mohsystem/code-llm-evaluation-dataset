import hashlib

def get_hash(password):
    return hashlib.sha256(password.encode()).hexdigest()

def authenticate(input_password, stored_password_hash):
    return get_hash(input_password) == stored_password_hash

stored_password_hash = get_hash("securepassword")
input_password = input("Enter your password: ")

if authenticate(input_password, stored_password_hash):
    print("Authentication successful.")
else:
    print("Authentication failed.")