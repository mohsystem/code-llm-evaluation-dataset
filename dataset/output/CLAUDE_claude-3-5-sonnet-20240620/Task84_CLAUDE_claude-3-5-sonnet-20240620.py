
import uuid

def generate_session_id():
    return str(uuid.uuid4())

# Example usage
session_id = generate_session_id()
print(session_id)
