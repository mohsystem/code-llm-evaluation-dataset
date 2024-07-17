
import uuid

def generate_session_id():
    return str(uuid.uuid4())

if __name__ == "__main__":
    session_id = generate_session_id()
    print(f"Generated Session ID: {session_id}")
