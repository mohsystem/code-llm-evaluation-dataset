from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

def encrypt_data(plain_text):
    iv = bytes([0] * 16)  # static IV
    cipher = AES.new(key=b'your_secret_key_here', mode=AES.MODE_CBC, iv=iv)
    padded_data = pad(plain_text.encode(), AES.block_size)
    encrypted_data = cipher.encrypt(padded_data)
    return encrypted_data

# example usage:
plain_text = "Hello, World!"
encrypted_data = encrypt_data(plain_text)
print(encrypted_data.hex())