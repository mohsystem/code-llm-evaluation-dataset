
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

cJSON* parse_json_and_get_root(const char* json_string) {
    return cJSON_Parse(json_string);
}

int main() {
    const char* json_string = "{\\"name\\": \\"John\\", \\"age\\": 30, \\"city\\": \\"New York\\"}";
    cJSON* root_element = parse_json_and_get_root(json_string);
    
    if (root_element != NULL) {
        char* printed_json = cJSON_Print(root_element);
        printf("%s\\n", printed_json);
        free(printed_json);
        cJSON_Delete(root_element);
    } else {
        printf("Failed to parse JSON\\n");
    }

    return 0;
}
