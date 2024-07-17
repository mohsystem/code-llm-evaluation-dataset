#include <stdio.h>
#include <json-c/json.h>

int main() {
    const char *jsonString = "{\"name\": \"John\", \"age\": 30}";
    struct json_object *parsed_json;
    struct json_object *name;
    struct json_object *age;

    parsed_json = json_tokener_parse(jsonString);

    if (parsed_json == NULL) {
        printf("Error parsing JSON
");
        return 1;
    }

    json_object_object_get_ex(parsed_json, "name", &name);
    json_object_object_get_ex(parsed_json, "age", &age);

    printf("Name: %s
", json_object_get_string(name));
    printf("Age: %d
", json_object_get_int(age));

    json_object_put(parsed_json);

    return 0;
}