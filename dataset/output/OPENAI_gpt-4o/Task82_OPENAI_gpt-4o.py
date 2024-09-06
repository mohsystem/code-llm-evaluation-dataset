import hashlib

def compute_hash(password, salt):
    combined = password + salt
    return hashlib.sha256(combined.encode()).hexdigest()

password = "example_password"
salt = "random_salt"
print(f"Python Hash: {compute_hash(password, salt)}")