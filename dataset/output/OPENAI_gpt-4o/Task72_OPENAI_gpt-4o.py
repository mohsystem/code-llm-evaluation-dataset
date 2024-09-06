from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

def encrypt_data(data, key):
    iv = b'\x00' * 16  # Static IV
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_data = pad(data.encode('utf-8'), AES.block_size)
    encrypted_data = cipher.encrypt(padded_data)
    return encrypted_data

# Example usage
key = b'sixteen byte key'
data = 'Hello, World!'
encrypted_data = encrypt_data(data, key)
print(encrypted_data)