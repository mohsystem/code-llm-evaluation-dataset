import base64
import json

def process_request(request):
    raw_data = request.get_data(as_text=True)
    decoded_data = base64.b64decode(raw_data).decode('utf-8')
    deserialized_data = json.loads(decoded_data)
    return deserialized_data