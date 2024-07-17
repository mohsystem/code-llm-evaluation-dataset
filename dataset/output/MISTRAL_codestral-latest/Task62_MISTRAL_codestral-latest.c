#include <stdio.h>
#include <jansson.h>

int main() {
    const char *jsonString = "{\"key1\":\"value1\",\"key2\":\"value2\"}";
    json_t *root;
    json_error_t error;

    root = json_loads(jsonString, 0, &error);
    if(!root) {
        fprintf(stderr, "error: on line %d: %s
", error.line, error.text);
        return 1;
    }

    void *iter = json_object_iter(root);
    const char *key = json_object_iter_key(iter);
    printf("Root element: %s
", key);

    json_decref(root);
    return 0;
}