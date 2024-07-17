from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
import base64

def encrypt_key(key):
  """Encrypts a key using AES in CBC mode.

  Args:
    key: The key to encrypt.

  Returns:
    A tuple containing the encrypted key and the initialization vector (IV),
    both encoded in Base64.
  """
  # Generate a random IV
  iv = get_random_bytes(AES.block_size)

  # Create a cipher object
  cipher = AES.new(key, AES.MODE_CBC, iv)

  # Encrypt the key
  encrypted_key = cipher.encrypt(key)

  # Encode the encrypted key and IV in Base64
  encoded_encrypted_key = base64.b64encode(encrypted_key).decode('utf-8')
  encoded_iv = base64.b64encode(iv).decode('utf-8')

  return encoded_encrypted_key, encoded_iv

# Generate a random key to encrypt
key = get_random_bytes(16)

# Encrypt the key
encrypted_key, encoded_iv = encrypt_key(key)

# Print the encrypted key and IV
print(f"Encrypted Key (Base64): {encrypted_key}")
print(f"IV (Base64): {encoded_iv}")