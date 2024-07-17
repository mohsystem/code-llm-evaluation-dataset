import json

json_string = "{\"key1\":\"value1\",\"key2\":\"value2\"}"
json_object = json.loads(json_string)
print("Root element:", next(iter(json_object)))