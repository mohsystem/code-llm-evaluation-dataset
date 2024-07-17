import json

jsonString = '{"name":"John", "age":30, "car":null}'
obj = json.loads(jsonString)
root_key = next(iter(obj.keys()))
print("Root Element:", root_key)