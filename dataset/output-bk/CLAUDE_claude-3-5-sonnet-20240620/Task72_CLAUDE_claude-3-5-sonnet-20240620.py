
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import os

class AESEncryption:
    def __init__(self):
        self.iv = os.urandom(AES.block_size)

    def encrypt(self, data, key):
        cipher = AES.new(key.encode(), AES.MODE_CBC, self.iv)
        padded_data = pad(data.encode(), AES.block_size)
        encrypted_data = cipher.encrypt(padded_data)
        return encrypted_data

if __name__ == "__main__":
    aes = AESEncryption()
    data = "Hello, World!"
    key = "1234567890123456"

    encrypted = aes.encrypt(data, key)
    print("Encrypted:", encrypted.hex())
