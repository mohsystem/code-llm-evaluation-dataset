import uuid

def generate_token():
    return str(uuid.uuid4())

if __name__ == "__main__":
    print("Python Token:", generate_token())