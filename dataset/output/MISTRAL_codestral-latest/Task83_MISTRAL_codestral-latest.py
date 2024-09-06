# Python
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes

def encrypt_key(key, cipher_key):
    cipher = AES.new(cipher_key, AES.MODE_CBC)
    cipher_text = cipher.encrypt(pad(key, AES.block_size))
    return cipher.iv + cipher_text

# Example usage
key = b'This is a key123'
cipher_key = get_random_bytes(16)
encrypted_key = encrypt_key(key, cipher_key)
print(encrypted_key)