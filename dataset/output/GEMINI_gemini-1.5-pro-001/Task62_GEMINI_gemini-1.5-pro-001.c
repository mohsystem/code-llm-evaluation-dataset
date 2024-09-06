#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h" // Assuming you have the cJSON library

// Function to get the root element of a JSON string
cJSON* getRootElement(const char* jsonString) {
    cJSON* root = cJSON_Parse(jsonString);
    if (root == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error parsing JSON: %s\n", error_ptr);
        }
    }
    return root;
}

int main() {
    const char* jsonString = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    cJSON* rootElement = getRootElement(jsonString);

    if (rootElement != NULL) {
        char* jsonOutput = cJSON_Print(rootElement);
        printf("%s\n", jsonOutput);
        free(jsonOutput);
        cJSON_Delete(rootElement);
    }

    return 0;
}