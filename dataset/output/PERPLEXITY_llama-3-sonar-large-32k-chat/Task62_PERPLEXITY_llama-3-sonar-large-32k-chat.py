import json

def get_root_element(json_string):
    json_data = json.loads(json_string)
    return type(json_data).__name__

json_string = '{"name":"John", "age":30, "city":"New York"}'
print(get_root_element(json_string))