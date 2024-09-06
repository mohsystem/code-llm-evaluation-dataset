import random

def generate_random_string(length):
  """Generates a random string of ASCII letters.

  Args:
    length: The desired length of the string.

  Returns:
    A string of random ASCII letters.
  """
  letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
  return ''.join(random.choice(letters) for _ in range(length))