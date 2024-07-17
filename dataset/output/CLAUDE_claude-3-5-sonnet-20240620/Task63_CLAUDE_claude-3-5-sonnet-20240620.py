
import base64
import json

def process_request(raw_data):
    try:
        # Ensure raw_data is UTF-8 encoded
        utf8_encoded_data = raw_data.encode(\'utf-8\')
        
        # Decode Base64
        decoded_data = base64.b64decode(utf8_encoded_data).decode(\'utf-8\')
        
        # Deserialize JSON
        deserialized_data = json.loads(decoded_data)
        
        # Return the deserialized data
        return deserialized_data
    except Exception as e:
        print(f"Error: {str(e)}")
        return None

if __name__ == "__main__":
    raw_data = "eyJuYW1lIjogIkpvaG4gRG9lIiwgImFnZSI6IDMwfQ=="
    result = process_request(raw_data)
    print(json.dumps(result, indent=2))
