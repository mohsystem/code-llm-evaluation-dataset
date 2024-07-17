import json

def deserialize(data):
    try:
        return json.loads(data)
    except json.JSONDecodeError as e:
        return f"Error decoding JSON: {e}"

data = '{"name": "John", "age": 30}'
deserialized_data = deserialize(data)
print(deserialized_data)