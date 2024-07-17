import base64
import json

def process_request(request_data):
    # Step 1: Retrieve and decode raw data
    decoded_data = base64.b64decode(request_data).decode('utf-8')

    # Step 2: Deserialize JSON data
    deserialized_data = json.loads(decoded_data)

    # Step 3: Store deserialized data in variable and return it
    stored_data = deserialized_data
    return stored_data

# Example usage
request_data = "eyJrZXkiOiAiVmFsdWUifQ=="
stored_data = process_request(request_data)
print(stored_data)