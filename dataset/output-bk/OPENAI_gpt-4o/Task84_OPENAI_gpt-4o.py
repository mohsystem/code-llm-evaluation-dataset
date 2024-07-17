import random
import string

def generate_session_id(length=16):
    characters = string.ascii_letters + string.digits
    return ''.join(random.choice(characters) for i in range(length))

if __name__ == "__main__":
    print(f"Python Session ID: {generate_session_id()}")