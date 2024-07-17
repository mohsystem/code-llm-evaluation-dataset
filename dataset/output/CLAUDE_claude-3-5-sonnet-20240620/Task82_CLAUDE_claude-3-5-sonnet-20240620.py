
import hashlib

def hash_password(password, salt):
    combined = password + salt
    hashed = hashlib.sha256(combined.encode()).hexdigest()
    return hashed

password = "myPassword123"
salt = "randomSalt"
hashed_password = hash_password(password, salt)
print("Hashed password:", hashed_password)
