import random
import string

def generate_token(length=32):
    characters = string.ascii_letters + string.digits
    token = ''.join(random.choice(characters) for _ in range(length))
    return token

# Example usage:
token = generate_token()
print(token)