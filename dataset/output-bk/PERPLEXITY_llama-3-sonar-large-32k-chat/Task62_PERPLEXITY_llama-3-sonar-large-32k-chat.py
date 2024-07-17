import json

def main():
    json_string = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}"
    json_obj = json.loads(json_string)
    print("Root element:", list(json_obj.keys())[0])

if __name__ == "__main__":
    main()