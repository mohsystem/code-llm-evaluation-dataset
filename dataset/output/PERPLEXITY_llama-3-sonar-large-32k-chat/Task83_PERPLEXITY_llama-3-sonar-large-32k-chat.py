from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import base64

def encrypt_aes_cbc(key, plaintext):
    cipher = AES.new(key, AES.MODE_CBC, iv='\0'*16)
    ct_bytes = cipher.encrypt(pad(plaintext.encode('utf-8'), AES.block_size))
    return base64.b64encode(ct_bytes).decode('utf-8')

key = b'\0'*16  # 16 byte key
plaintext = "Hello, World!"
print(encrypt_aes_cbc(key, plaintext))