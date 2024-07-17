
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>

json_object* parse_json(const char* json_string) {
    json_object* root = json_tokener_parse(json_string);
    if (root == NULL) {
        fprintf(stderr, "Failed to parse JSON\
");
        return NULL;
    }
    return root;
}

int main() {
    const char* json_string = "{\\"name\\":\\"John\\",\\"age\\":30,\\"city\\":\\"New York\\"}";
    json_object* root_element = parse_json(json_string);
    
    if (root_element != NULL) {
        printf("Root element: %s\
", json_object_to_json_string(root_element));
        json_object_put(root_element);
    }
    
    return 0;
}
