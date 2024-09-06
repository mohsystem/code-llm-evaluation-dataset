import base64
import json

# Function to process the request
def process_request(req):
    # Step 1: Retrieve the raw_data from the request, ensuring it is encoded in UTF-8
    raw_data = req.encode('utf-8')
    
    # Step 2: Decode the raw_data using Base64
    decoded_data = base64.b64decode(raw_data)
    
    # Step 3: Deserialize the decoded data into its original format (e.g., JSON)
    deserialized_data = json.loads(decoded_data)
    
    # Step 4: Store the deserialized data in a variable
    stored_data = deserialized_data
    
    # Step 5: Return the stored data
    return stored_data

# Example usage
req = base64.b64encode(json.dumps({"key": "value"}).encode('utf-8')).decode('utf-8')
print(process_request(req))