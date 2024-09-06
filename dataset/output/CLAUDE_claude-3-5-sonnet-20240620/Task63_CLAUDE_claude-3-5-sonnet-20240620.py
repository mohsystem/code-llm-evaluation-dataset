
import base64
import json

def process_request(raw_data):
    # Ensure raw_data is UTF-8 encoded
    raw_data = raw_data.encode('utf-8') if isinstance(raw_data, str) else raw_data
    
    # Decode the raw_data using Base64
    decoded_data = base64.b64decode(raw_data)
    
    # Deserialize the decoded data (assuming JSON in this example)
    deserialized_data = json.loads(decoded_data)
    
    # Store the deserialized data in a variable
    stored_data = deserialized_data
    
    # Return the stored data
    return stored_data

# Example usage
raw_input = "eyJuYW1lIjogIkpvaG4gRG9lIiwgImFnZSI6IDMwfQ=="
result = process_request(raw_input)
print(result)
