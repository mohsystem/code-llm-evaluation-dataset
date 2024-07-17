# Python
import uuid

def generate_token():
    token = uuid.uuid4()
    print("Generated Token: ", token)

generate_token()