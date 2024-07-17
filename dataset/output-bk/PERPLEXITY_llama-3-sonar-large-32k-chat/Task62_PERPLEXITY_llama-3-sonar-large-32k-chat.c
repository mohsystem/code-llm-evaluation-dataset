#include <stdio.h>
#include <json-c/json.h>

int main() {
    const char *json_string = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    struct json_object *json_obj = json_tokener_parse(json_string);
    struct json_object *root_obj = json_object_object_object_get(json_obj, "name");
    printf("Root element: %s
", json_object_get_string(root_obj));
    json_object_put(json_obj);
    return 0;
}