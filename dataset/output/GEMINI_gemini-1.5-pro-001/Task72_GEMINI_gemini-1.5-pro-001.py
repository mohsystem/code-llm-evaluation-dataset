from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

# Static Initialization Vector (IV) - Must be 16 bytes
iv = b'ThisIsMyStaticIV'

# Encryption Key - Must be 16, 24, or 32 bytes
key = b'ThisIsMySecretKey'

def encrypt_data(data):
  """
  Encrypts data using AES-CBC with a static IV.

  Args:
    data: The data to be encrypted (bytes).

  Returns:
    The encrypted data (bytes).
  """
  cipher = AES.new(key, AES.MODE_CBC, iv)
  padded_data = pad(data, AES.block_size)
  encrypted_data = cipher.encrypt(padded_data)
  return encrypted_data

# Example usage
data = b'This is some secret data.'
encrypted_data = encrypt_data(data)
print(encrypted_data)