import hashlib

def hash_password(password, salt):
  """Computes the hash of a password combined with a salt.

  Args:
    password: The password to hash.
    salt: The salt to use.

  Returns:
    The hash of the password and salt.
  """

  salted_password = salt + password.encode('utf-8')
  hashed_password = hashlib.sha256(salted_password).hexdigest()
  return hashed_password