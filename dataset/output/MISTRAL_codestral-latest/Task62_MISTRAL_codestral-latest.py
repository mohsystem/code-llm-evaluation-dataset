import json

def get_root_element(json_string):
    json_data = json.loads(json_string)
    return list(json_data.keys())[0]