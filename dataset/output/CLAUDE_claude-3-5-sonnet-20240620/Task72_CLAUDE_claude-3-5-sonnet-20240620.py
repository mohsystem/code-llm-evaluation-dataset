
import os
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import padding

def encrypt_data(data, key):
    # Create a static initialization vector (IV)
    iv = b'\\x00' * 16

    # Initialize a cipher using AES in CBC mode with the static IV
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
    encryptor = cipher.encryptor()

    # Pad the input data to match the block size required by the cipher
    padder = padding.PKCS7(128).padder()
    padded_data = padder.update(data) + padder.finalize()

    # Encrypt the padded data using the cipher
    encrypted_data = encryptor.update(padded_data) + encryptor.finalize()

    return encrypted_data

# Example usage
key = os.urandom(32)  # 256-bit key
data = b"This is a secret message."
encrypted = encrypt_data(data, key)
print(encrypted)
