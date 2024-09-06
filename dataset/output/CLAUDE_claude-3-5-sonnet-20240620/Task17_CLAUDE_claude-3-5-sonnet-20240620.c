
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* to_jaden_case(char* string) {
    if (string == NULL || *string == '\\0') return string;
    
    char* result = malloc(strlen(string) + 1);
    char* p = result;
    int new_word = 1;
    
    while (*string) {
        if (isspace(*string)) {
            new_word = 1;
            *p++ = *string++;
        } else if (new_word) {
            *p++ = toupper(*string++);
            new_word = 0;
        } else {
            *p++ = *string++;
        }
    }
    *p = '\\0';
    
    return result;
}
