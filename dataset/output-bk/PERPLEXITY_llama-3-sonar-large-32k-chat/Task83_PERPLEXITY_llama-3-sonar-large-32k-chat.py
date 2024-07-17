from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import os
import base64

def encrypt_key(key, iv):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_key = pad(key, AES.block_size)
    encrypted_key = cipher.encrypt(padded_key)
    return encrypted_key

key = os.urandom(16)
iv = os.urandom(16)

encrypted_key = encrypt_key(key, iv)

print("IV: ", base64.b64encode(iv).decode())
print("Encrypted Key: ", base64.b64encode(encrypted_key).decode())