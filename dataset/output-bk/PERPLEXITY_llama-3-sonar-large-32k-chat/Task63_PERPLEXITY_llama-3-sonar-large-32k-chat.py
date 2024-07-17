import base64
import json

def process_request(raw_data):
    # Ensure raw_data is encoded in UTF-8
    utf8_bytes = raw_data.encode('utf-8')

    # Decode the raw_data using Base64
    decoded_bytes = base64.b64decode(utf8_bytes)
    decoded_data = decoded_bytes.decode('utf-8')

    # Deserialize the decoded data into its original format (e.g., JSON)
    deserialized_data = json.loads(decoded_data)

    # Store the deserialized data in a variable
    stored_data = json.dumps(deserialized_data)

    # Return the stored data
    return stored_data

raw_data = "Your raw data here"
result = process_request(raw_data)
print(result)