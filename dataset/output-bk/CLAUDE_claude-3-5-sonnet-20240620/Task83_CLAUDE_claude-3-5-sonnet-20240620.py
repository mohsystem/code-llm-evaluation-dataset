
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes
import base64

def encrypt_aes_cbc(key, plaintext):
    iv = get_random_bytes(AES.block_size)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_data = pad(plaintext.encode(), AES.block_size)
    ciphertext = cipher.encrypt(padded_data)
    return base64.b64encode(iv + ciphertext).decode(\'utf-8\')

key = b\'Sixteen byte key\'
plaintext = "Text to be encrypted"

encrypted = encrypt_aes_cbc(key, plaintext)
print(f"Encrypted: {encrypted}")
