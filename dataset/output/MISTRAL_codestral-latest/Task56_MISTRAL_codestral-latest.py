import hashlib
import time

def generate_token(username, password):
    timestamp = str(time.time())
    data = username + password + timestamp
    token = hashlib.sha256(data.encode()).hexdigest()
    return token