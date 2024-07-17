# Python
import hashlib
import os

def hash_password(password, salt):
    hashed_password = hashlib.sha256(salt + password.encode()).hexdigest()
    for i in range(10000):
        hashed_password = hashlib.sha256(hashed_password.encode()).hexdigest()
    return hashed_password

password = "your_password"
salt = os.urandom(16)
hashed_password = hash_password(password, salt)
print(hashed_password)