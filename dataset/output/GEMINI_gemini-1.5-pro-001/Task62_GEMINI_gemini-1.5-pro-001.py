import json

def parse_json(json_string):
  """Parses the provided JSON string and returns the root element."""

  try:
    parsed_json = json.loads(json_string)
    return parsed_json
  except json.JSONDecodeError:
    print("Invalid JSON string provided.")
    return None

if __name__ == "__main__":
  json_string = '{"name":"John", "age":30, "city":"New York"}'
  root_element = parse_json(json_string)
  if root_element:
    print("Root element:", root_element)