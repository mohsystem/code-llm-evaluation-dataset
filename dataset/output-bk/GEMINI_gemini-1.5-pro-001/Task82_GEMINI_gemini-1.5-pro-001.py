import hashlib
import os

def hash_password(password, salt=None):
  """Hashes a password with a salt.

  Args:
    password: The password to hash.
    salt: The salt to use. If None, a random salt will be generated.

  Returns:
    The hashed password and salt, separated by a colon.
  """

  if salt is None:
    salt = os.urandom(16)
  else:
    salt = salt.encode('utf-8')

  password = password.encode('utf-8')

  hashed_password = hashlib.pbkdf2_hmac(
      'sha256',
      password,
      salt,
      100000
  )

  return f"{salt.hex()}:{hashed_password.hex()}"