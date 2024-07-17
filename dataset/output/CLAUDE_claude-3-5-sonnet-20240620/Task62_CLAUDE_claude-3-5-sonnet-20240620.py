
import json

def parse_json(json_string):
    try:
        return json.loads(json_string)
    except json.JSONDecodeError as e:
        print(f"JSON parse error: {e}")
        return None

if __name__ == "__main__":
    json_string = \'{"name":"John","age":30,"city":"New York"}\'
    root_element = parse_json(json_string)
    
    if root_element is not None:
        print(f"Root element: {root_element}")
