from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC

# Input key
key = b"This is a secret key"
# Input data to encrypt
data = b"This is a secret message"

# Generate a random salt
salt = b'\x91\x85\x06\xbe\x8a\xca\x85\x16R\xb9\x1c\xb2k\xe1\xd5\x98'

# Derive a 256-bit key from the input key and salt
kdf = PBKDF2HMAC(
    algorithm=hashes.SHA256(),
    length=32,
    salt=salt,
    iterations=390000,
    backend=default_backend()
)
key = kdf.derive(key)

# Generate a random initialization vector (IV)
iv = b'\xb5\xf7"\x90\xb2\x84\x94\x15\x17\x11\x81\x98\x9e\x9a\xb3'

# Create the AES-CBC cipher object
cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())

# Encrypt the data
encryptor = cipher.encryptor()
ct = encryptor.update(data) + encryptor.finalize()

# Print the encrypted data in base64 encoding
print(ct.hex())