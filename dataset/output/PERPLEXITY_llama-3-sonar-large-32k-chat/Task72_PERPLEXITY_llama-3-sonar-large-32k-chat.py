from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import os

def encrypt_data(data, key):
    iv = os.urandom(16)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_data = pad(data.encode(), AES.block_size)
    encrypted_data = cipher.encrypt(padded_data)
    return iv + encrypted_data

key = b"Bar12345678901234"
data = "Hello, World!"
encrypted_data = encrypt_data(data, key)
print(encrypted_data.hex())