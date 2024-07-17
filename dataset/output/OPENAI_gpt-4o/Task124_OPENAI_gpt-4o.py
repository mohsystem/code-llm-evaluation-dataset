import base64

class SecureData:
    def __init__(self, data):
        self.encoded_data = self.encode_data(data)
    
    def encode_data(self, data):
        return base64.b64encode(data.encode('utf-8')).decode('utf-8')
    
    def decode_data(self):
        return base64.b64decode(self.encoded_data.encode('utf-8')).decode('utf-8')

sensitive_data = SecureData("4111-1111-1111-1111")
print(f"Encoded Data (Python): {sensitive_data.encoded_data}")
print(f"Decoded Data (Python): {sensitive_data.decode_data()}")