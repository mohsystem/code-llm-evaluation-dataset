#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* toJadenCase(char* phrase) {
    if (phrase == NULL || strlen(phrase) == 0) return NULL;
    char* result = malloc(strlen(phrase) + 1);
    char* p = phrase;
    char* q = result;
    while (*p != '\0') {
        *q = toupper(*p);
        p++;
        q++;
        while (*p != ' ' && *p != '\0') {
            *q = tolower(*p);
            p++;
            q++;
        }
        *q = ' ';
        q++;
    }
    *(q - 1) = '\0';
    return result;
}