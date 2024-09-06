from cryptography.fernet import Fernet

def encrypt_message(message, key):
  """Encrypts a message using a secret key.

  Args:
    message: The message to encrypt.
    key: The secret key to use for encryption.

  Returns:
    The encrypted message.
  """
  cipher = Fernet(key)
  encrypted_message = cipher.encrypt(message.encode())
  return encrypted_message.decode()