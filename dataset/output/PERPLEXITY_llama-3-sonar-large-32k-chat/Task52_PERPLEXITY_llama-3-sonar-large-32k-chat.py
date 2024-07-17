from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import os

def encrypt(file_to_encrypt, encrypted_file, key):
    cipher = AES.new(key, AES.MODE_ECB)
    with open(file_to_encrypt, 'rb') as fis:
        with open(encrypted_file, 'wb') as fos:
            while True:
                buffer = fis.read(1024)
                if not buffer:
                    break
                padded_buffer = pad(buffer, AES.block_size)
                encrypted_buffer = cipher.encrypt(padded_buffer)
                fos.write(encrypted_buffer)

def decrypt(encrypted_file, decrypted_file, key):
    cipher = AES.new(key, AES.MODE_ECB)
    with open(encrypted_file, 'rb') as fis:
        with open(decrypted_file, 'wb') as fos:
            while True:
                buffer = fis.read(1024)
                if not buffer:
                    break
                decrypted_buffer = cipher.decrypt(buffer)
                unpadded_buffer = unpad(decrypted_buffer, AES.block_size)
                fos.write(unpadded_buffer)

def main():
    file_to_encrypt = "input.txt"
    encrypted_file = "encrypted.txt"
    decrypted_file = "decrypted.txt"
    key = os.urandom(16)  # 16 bytes key for AES-128

    encrypt(file_to_encrypt, encrypted_file, key)
    decrypt(encrypted_file, decrypted_file, key)

if __name__ == "__main__":
    main()