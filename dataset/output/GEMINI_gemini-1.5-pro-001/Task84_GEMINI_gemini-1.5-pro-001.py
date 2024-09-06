import random
import string

def generate_session_id(length=16):
  """Generates a random and unique session ID.

  Args:
    length: The desired length of the session ID.

  Returns:
    A string representing the session ID.
  """
  return ''.join(random.choices(string.ascii_letters + string.digits, k=length))