import uuid
import hashlib
import time

def generate_token(username, password):
    timestamp = str(int(time.time()))
    token_str = username + password + timestamp
    token_hash = hashlib.sha256(token_str.encode()).hexdigest()
    return token_hash

username = "john"
password = "password123"
print("Token:", generate_token(username, password))