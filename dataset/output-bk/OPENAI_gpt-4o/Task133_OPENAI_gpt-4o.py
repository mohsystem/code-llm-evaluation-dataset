import hashlib

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def validate_password(password, hashed_password):
    return hash_password(password) == hashed_password

print("Python: Enter your current password:")
current_password = input()
hashed_password = hash_password(current_password)

print("Python: Enter new password:")
new_password = input()
hashed_new_password = hash_password(new_password)

print("Python: Password has been reset!")