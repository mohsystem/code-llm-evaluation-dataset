from Crypto.Cipher import AES
import base64

def encrypt(input: str, key: str, iv: str) -> bytes:
    cipher = AES.new(key.encode('utf-8'), AES.MODE_CBC, iv.encode('utf-8'))
    padded_input = input + (AES.block_size - len(input) % AES.block_size) * chr(AES.block_size - len(input) % AES.block_size)
    encrypted = cipher.encrypt(padded_input.encode('utf-8'))
    return base64.b64encode(encrypted)

def runPython():
    input = "This is a secret message."
    key = "1234567890123456"
    iv = "abcdef1234567890"
    encrypted = encrypt(input, key, iv)
    print("Encrypted (Python):", encrypted.decode())

if __name__ == "__main__":
    runPython()