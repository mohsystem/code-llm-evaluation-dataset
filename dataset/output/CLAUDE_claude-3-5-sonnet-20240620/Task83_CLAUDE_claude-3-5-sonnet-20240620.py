
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes
import base64

def encrypt_key(key):
    iv = get_random_bytes(AES.block_size)
    cipher = AES.new(get_random_bytes(32), AES.MODE_CBC, iv)
    ct_bytes = cipher.encrypt(pad(key.encode('utf-8'), AES.block_size))
    ct = base64.b64encode(iv + ct_bytes).decode('utf-8')
    return ct

# Example usage
key_to_encrypt = "MySecretKey123456"
encrypted_key = encrypt_key(key_to_encrypt)
print(f"Encrypted key: {encrypted_key}")
