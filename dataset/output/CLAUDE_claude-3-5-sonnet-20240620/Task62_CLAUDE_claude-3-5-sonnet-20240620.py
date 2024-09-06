
import json

def parse_json_and_get_root(json_string):
    try:
        parsed_json = json.loads(json_string)
        return parsed_json
    except json.JSONDecodeError:
        return None

# Example usage
json_string = '{"name": "John", "age": 30, "city": "New York"}'
root_element = parse_json_and_get_root(json_string)
print(root_element)
