import json

def deserialize(data):
  """Deserializes the given data.

  Args:
    data: A string containing the data to deserialize.

  Returns:
    The deserialized data.
  """

  try:
    return json.loads(data)
  except json.JSONDecodeError:
    print("Error: Invalid JSON data.")
    return None

if __name__ == "__main__":
  user_data = input("Enter the data to deserialize: ")
  deserialized_data = deserialize(user_data)

  if deserialized_data is not None:
    print("Deserialized data:", deserialized_data)