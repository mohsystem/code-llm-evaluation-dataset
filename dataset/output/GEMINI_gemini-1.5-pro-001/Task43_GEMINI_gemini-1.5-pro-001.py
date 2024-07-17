import random
import string

# Simplified session store (replace with database in production)
session_store = {}

def generate_session_id(length=32):
    return ''.join(random.choices(string.ascii_lowercase, k=length))

def create_session(username):
    session_id = generate_session_id()
    session_store[session_id] = {'username': username}
    return session_id

def get_session(session_id):
    return session_store.get(session_id)

def terminate_session(session_id):
    session_store.pop(session_id, None)

# Example usage:
new_session_id = create_session("user123")
print(f"Session created with ID: {new_session_id}")

# ... (Further session management operations)