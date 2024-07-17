
import pickle
import base64

def deserialize_data():
    serialized_data = input("Enter the serialized data: ")
    try:
        decoded_data = base64.b64decode(serialized_data)
        deserialized_data = pickle.loads(decoded_data)
        print("Deserialized data:", deserialized_data)
    except:
        print("Error: Invalid input or deserialization failed.")

if __name__ == "__main__":
    deserialize_data()
