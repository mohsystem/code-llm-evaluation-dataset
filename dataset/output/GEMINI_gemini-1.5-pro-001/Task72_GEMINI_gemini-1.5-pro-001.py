from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import base64

# Key and IV (replace with your own secure values)
key = b'YourSecretKeyHere'  
iv = b'\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f'

def encrypt_data(key, iv, data):
    """Encrypts data using AES-128 in CBC mode.

    Args:
        key: The encryption key (16 bytes).
        iv: The initialization vector (16 bytes).
        data: The data to encrypt (bytes).

    Returns:
        The encrypted data (bytes).
    """
    cipher = AES.new(key, AES.MODE_CBC, iv)
    ciphertext = cipher.encrypt(pad(data, AES.block_size))
    return ciphertext

# Example usage
plaintext = b'This is some data to encrypt.'
ciphertext = encrypt_data(key, iv, plaintext)
base64_ciphertext = base64.b64encode(ciphertext).decode('utf-8')

# Output Base64 encoded ciphertext
print(base64_ciphertext)