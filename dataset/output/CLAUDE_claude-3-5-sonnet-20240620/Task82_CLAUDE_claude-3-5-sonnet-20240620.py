
import hashlib

def hash_password(password, salt):
    combined = password.encode() + salt.encode()
    return hashlib.sha256(combined).hexdigest()

# Example usage
password = "mypassword123"
salt = "randomsalt"
hashed_password = hash_password(password, salt)
print(f"Hashed password: {hashed_password}")
