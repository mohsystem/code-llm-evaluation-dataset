
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** number(const char** lines, size_t linesCount) {
    if (linesCount == 0) return NULL;
    
    char** result = malloc(linesCount * sizeof(char*));
    for (size_t i = 0; i < linesCount; i++) {
        size_t len = strlen(lines[i]) + 20;  // Extra space for number and ": "
        result[i] = malloc(len * sizeof(char));
        snprintf(result[i], len, "%zu: %s", i + 1, lines[i]);
    }
    
    return result;
}
