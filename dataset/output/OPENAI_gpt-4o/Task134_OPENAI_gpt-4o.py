import os
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import rsa

def generate_key():
    key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    return key

def save_key(key, filename):
    with open(filename, "wb") as key_file:
        key_file.write(
            key.private_bytes(
                encoding=serialization.Encoding.PEM,
                format=serialization.PrivateFormat.PKCS8,
                encryption_algorithm=serialization.NoEncryption(),
            )
        )

def load_key(filename):
    with open(filename, "rb") as key_file:
        key = serialization.load_pem_private_key(
            key_file.read(),
            password=None,
        )
    return key

key = generate_key()
save_key(key, "private_key.pem")
loaded_key = load_key("private_key.pem")
print(f"Key: {loaded_key}")