import json

def get_root_element(json_string):
  """
  Parses a JSON string and returns the root element.

  Args:
    json_string: The JSON string to parse.

  Returns:
    The root element of the JSON document, which can be a dictionary, a list,
    or a primitive value.
  """
  try:
    parsed_json = json.loads(json_string)
    return parsed_json
  except json.JSONDecodeError as e:
    print(f"Invalid JSON string: {e}")
    return None

# Example usage:
json_string = '{"name": "John", "age": 30, "city": "New York"}'
root_element = get_root_element(json_string)
print(root_element)