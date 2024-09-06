#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>

int main() {
    const char *jsonString = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";

    json_error_t error;
    json_t *root = json_loads(jsonString, 0, &error);

    if (!root) {
        fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
        return 1;
    }

    char *jsonDump = json_dumps(root, JSON_INDENT(2));
    printf("%s\n", jsonDump);

    free(jsonDump);
    json_decref(root);

    return 0;
}