import pickle

def deserialize_data(data):
    try:
        return pickle.loads(data)
    except pickle.UnpicklingError as e:
        print(f"Error deserializing data: {e}")
        return None

data = input("Enter serialized data: ")
deserialized_data = deserialize_data(data)
print("Deserialized data:", deserialized_data)