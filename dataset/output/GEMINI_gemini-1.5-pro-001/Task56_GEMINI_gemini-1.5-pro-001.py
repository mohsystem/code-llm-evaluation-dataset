import secrets
import string

def generate_token(length=32):
  """Generates a random token of specified length."""
  return ''.join(secrets.choice(string.ascii_letters + string.digits) for _ in range(length))

# Generate and print a token
token = generate_token()
print(token)