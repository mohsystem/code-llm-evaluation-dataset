#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *to_jaden_case(char *str) {
    if (str == NULL || strlen(str) == 0) {
        return NULL;
    }

    size_t len = strlen(str);
    char *result = (char *)malloc(len + 1); 
    if (result == NULL) {
        return NULL; 
    }

    int i = 0;
    int new_word = 1; 

    while (str[i]) {
        if (isspace(str[i])) {
            result[i] = str[i];
            new_word = 1; 
        } else {
            if (new_word) {
                result[i] = toupper(str[i]);
                new_word = 0;
            } else {
                result[i] = tolower(str[i]);
            }
        }
        i++;
    }

    result[len] = '\0'; 
    return result;
}