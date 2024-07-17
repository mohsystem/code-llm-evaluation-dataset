#include <stdio.h>
#include <json-c/json.h>

int main() {
    const char *jsonString = "{\"name\":\"John\", \"age\":30, \"car\":null}";
    struct json_object *parsed_json;
    struct lh_table *object;
    parsed_json = json_tokener_parse(jsonString);
    
    object = json_object_get_object(parsed_json);
    printf("Root Element: %s
", (char *)lh_table_get_key(object->head));
    
    return 0;
}