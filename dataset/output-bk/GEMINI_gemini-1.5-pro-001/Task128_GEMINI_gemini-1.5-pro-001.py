import random

def generate_random_number(min=0, max=100):
  """
  Generates a random number within a specified range.

  Args:
    min: The minimum value of the range (inclusive).
    max: The maximum value of the range (inclusive).

  Returns:
    A random integer within the specified range.
  """
  return random.randint(min, max)

def generate_random_token(length=16, chars="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"):
  """
  Generates a random token of a specified length.

  Args:
    length: The desired length of the token.
    chars: The set of characters to choose from.

  Returns:
    A random token string.
  """
  return ''.join(random.choice(chars) for _ in range(length))

# Example usage:
number = generate_random_number(1, 10)
print(f"Random number between 1 and 10: {number}")

token = generate_random_token(20)
print(f"Random token of length 20: {token}")