import hashlib

def compute_hash(password, salt):
    return hashlib.sha256((password + salt).encode()).hexdigest()

password = "mysecretpassword"
salt = "mysalt"
print(compute_hash(password, salt))