from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
import base64

def aes_encrypt(key, data):
    cipher = AES.new(key, AES.MODE_CBC)
    ciphertext = cipher.encrypt(data)
    iv = base64.b64encode(cipher.iv).decode('utf-8')
    enc_message = base64.b64encode(ciphertext).decode('utf-8')
    return iv + enc_message

key = get_random_bytes(32)  # AES-256
data = get_random_bytes(16)  # Input data must be a multiple of 16 bytes

encrypted_result = aes_encrypt(key, data)
print(encrypted_result)