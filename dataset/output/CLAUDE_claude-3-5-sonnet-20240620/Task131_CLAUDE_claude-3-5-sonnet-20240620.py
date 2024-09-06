
import json

def deserialize_data():
    serialized_data = input("Enter serialized data (JSON format): ")
    try:
        deserialized_data = json.loads(serialized_data)
        print("Deserialized data:")
        print(json.dumps(deserialized_data, indent=2))
    except json.JSONDecodeError:
        print("Error: Invalid JSON data")

if __name__ == "__main__":
    deserialize_data()
