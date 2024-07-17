
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* to_jaden_case(char* string) {
    if (string == NULL || *string == \'\\0\') {
        return NULL;
    }
    
    char* result = strdup(string);
    int len = strlen(result);
    int capitalize_next = 1;
    
    for (int i = 0; i < len; i++) {
        if (isspace(result[i])) {
            capitalize_next = 1;
        } else if (capitalize_next) {
            result[i] = toupper(result[i]);
            capitalize_next = 0;
        }
    }
    
    return result;
}
