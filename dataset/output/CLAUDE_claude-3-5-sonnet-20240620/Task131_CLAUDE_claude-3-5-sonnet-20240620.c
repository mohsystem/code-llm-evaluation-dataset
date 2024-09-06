
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter serialized data (JSON format): ");
    fgets(input, sizeof(input), stdin);

    cJSON *json = cJSON_Parse(input);
    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            printf("Error: %s\\n", error_ptr);
        }
        printf("Error: Invalid JSON data\\n");
    } else {
        char *printed_json = cJSON_Print(json);
        printf("Deserialized data:\\n%s\\n", printed_json);
        free(printed_json);
        cJSON_Delete(json);
    }

    return 0;
}
