
import hashlib
import os

users = {}

def hash_password(password, salt=None):
    if salt is None:
        salt = os.urandom(32)
    pwdhash = hashlib.pbkdf2_hmac('sha256', password.encode('utf-8'), salt, 100000)
    return salt + pwdhash

def verify_password(stored_password, provided_password):
    salt = stored_password[:32]
    stored_hash = stored_password[32:]
    pwdhash = hashlib.pbkdf2_hmac('sha256', provided_password.encode('utf-8'), salt, 100000)
    return pwdhash == stored_hash

def register(username, password):
    if username in users:
        return False
    users[username] = hash_password(password)
    return True

def login(username, password):
    if username not in users:
        return False
    return verify_password(users[username], password)

# Example usage
register("alice", "password123")
print(login("alice", "password123"))  # True
print(login("alice", "wrongpassword"))  # False
