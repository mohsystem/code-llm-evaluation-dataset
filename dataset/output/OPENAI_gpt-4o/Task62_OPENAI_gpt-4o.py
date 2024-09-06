import json

json_string = '{"name": "John", "age": 30, "city": "New York"}'

def get_root_element(json_str):
    try:
        parsed_json = json.loads(json_str)
        return parsed_json
    except json.JSONDecodeError as e:
        return None

root_element = get_root_element(json_string)
print(root_element)