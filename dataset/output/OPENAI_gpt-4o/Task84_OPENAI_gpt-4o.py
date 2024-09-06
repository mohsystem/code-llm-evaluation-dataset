import random
import string

def generate_session_id():
    characters = string.ascii_letters + string.digits
    session_id = ''.join(random.choices(characters, k=16))
    return session_id

print("Python generated session ID:", generate_session_id())