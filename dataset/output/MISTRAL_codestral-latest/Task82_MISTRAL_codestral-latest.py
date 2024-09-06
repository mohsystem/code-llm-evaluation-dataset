import hashlib
import binascii

def hash_password(password, salt):
    dk = hashlib.pbkdf2_hmac('sha256', password.encode(), salt, 100000)
    return binascii.hexlify(dk)

# Example usage:
password = "my_password"
salt = b'salt_'
hashed_password = hash_password(password, salt)
print(hashed_password)