
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import base64

def encrypt(message, secret_key):
    cipher = AES.new(secret_key.encode(\'utf-8\'), AES.MODE_ECB)
    padded_message = pad(message.encode(\'utf-8\'), AES.block_size)
    encrypted_message = cipher.encrypt(padded_message)
    return base64.b64encode(encrypted_message).decode(\'utf-8\')

message = "Hello, World!"
secret_key = "MySecretKey12345"

encrypted_message = encrypt(message, secret_key)
print("Encrypted message:", encrypted_message)
