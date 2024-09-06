import uuid
def generate_session_id():
    return str(uuid.uuid4())
print(generate_session_id())