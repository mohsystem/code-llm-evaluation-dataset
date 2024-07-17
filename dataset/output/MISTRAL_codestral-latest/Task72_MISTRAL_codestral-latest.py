# Python
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

KEY = b'1234567890123456' # 128 bit key
IV = b'RandomInitVector' # 16 bytes IV

def encrypt(plain_text):
    cipher = AES.new(KEY, AES.MODE_CBC, IV)
    cipher_text = cipher.encrypt(pad(plain_text, AES.block_size))
    return cipher_text