import pickle

def deserialize_data(data):
    try:
        return pickle.loads(data)
    except Exception as e:
        print("Error deserializing data:", e)
        return None

data = input("Enter serialized data: ")
deserialized_data = deserialize_data(data)
print("Deserialized data:", deserialized_data)