from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
import base64

# Generate a secret key
secret_key = get_random_bytes(16)

# Message to encrypt
message = "Hello, World!"

# Create cipher
cipher = AES.new(secret_key, AES.MODE_EAX)

# Encrypt message
ciphertext, tag = cipher.encrypt_and_digest(message.encode("utf-8"))

# Encode and print encrypted message in base64
encoded_message = base64.b64encode(cipher.nonce + ciphertext).decode("utf-8")
print("Encrypted Message (Python):", encoded_message)