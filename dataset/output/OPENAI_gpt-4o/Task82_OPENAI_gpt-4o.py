import hashlib

def sha256(str):
    return hashlib.sha256(str.encode()).hexdigest()

password = "password"
salt = "12345"
combined = password + salt
print(sha256(combined))