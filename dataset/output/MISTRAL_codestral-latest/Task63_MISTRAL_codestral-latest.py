# Python
import base64
import json

def processRequest(rawData):
    decodedBytes = base64.b64decode(rawData)
    decodedString = decodedBytes.decode('utf-8')
    return json.loads(decodedString)