from Crypto.Cipher import AES
import base64

def encrypt_message(message, secret_key):
    cipher = AES.new(secret_key.encode('utf-8'), AES.MODE_EAX)
    nonce = cipher.nonce
    ciphertext, tag = cipher.encrypt_and_digest(message.encode('utf-8'))
    return base64.b64encode(nonce + ciphertext).decode('utf-8')

# Example usage
message = "Secret Message"
secret_key = "thisisaverysecret"
encrypted_message = encrypt_message(message, secret_key)
print("Encrypted:", encrypted_message)