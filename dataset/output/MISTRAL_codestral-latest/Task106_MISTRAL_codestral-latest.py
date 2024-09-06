from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii

# Generate a new RSA key pair
key = RSA.generate(2048)

# Export the public key
public_key = key.publickey().exportKey()

# Create a cipher object using the public key
cipher = PKCS1_OAEP.new(RSA.importKey(public_key))

# Data to be encrypted
data = "Hello, World!"

# Encrypt the data
encrypted_data = cipher.encrypt(data.encode())

# Decrypt the data
decrypted_data = key.decrypt(encrypted_data)

print("Encrypted data:", binascii.hexlify(encrypted_data))
print("Decrypted data:", decrypted_data.decode())