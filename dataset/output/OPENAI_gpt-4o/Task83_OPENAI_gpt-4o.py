from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes

def aes_encrypt(key, data):
    cipher = AES.new(key, AES.MODE_CBC)
    ct_bytes = cipher.encrypt(pad(data, AES.block_size))
    return cipher.iv + ct_bytes

key = get_random_bytes(16)
data = b"exampleplaintext"
encrypted = aes_encrypt(key, data)
print(f"Encrypted Byte Array: {encrypted}")