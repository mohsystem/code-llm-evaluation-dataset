
import secrets
import string

def generate_token(length=32):
    alphabet = string.ascii_letters + string.digits
    token = \'\'.join(secrets.choice(alphabet) for _ in range(length))
    return token

if __name__ == "__main__":
    token = generate_token()
    print(f"Generated token: {token}")
