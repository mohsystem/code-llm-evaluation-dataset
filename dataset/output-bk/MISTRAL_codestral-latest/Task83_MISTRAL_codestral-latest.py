# Python
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
import base64

def encrypt(key, plaintext):
    cipher = AES.new(key, AES.MODE_CBC)
    ciphertext = cipher.encrypt(plaintext)
    return base64.b64encode(cipher.iv + ciphertext)

key = get_random_bytes(16)
plaintext = b'This is the plaintext to be encrypted'

encrypted_key = encrypt(key, plaintext)
print("Encrypted key:", encrypted_key)