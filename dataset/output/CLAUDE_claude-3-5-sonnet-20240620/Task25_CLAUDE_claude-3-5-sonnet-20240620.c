
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** number(const char** lines, size_t linesCount) {
    if (linesCount == 0) return NULL;
    
    char** result = (char**)malloc(linesCount * sizeof(char*));
    for (size_t i = 0; i < linesCount; i++) {
        size_t len = snprintf(NULL, 0, "%zu: %s", i + 1, lines[i]);
        result[i] = (char*)malloc((len + 1) * sizeof(char));
        snprintf(result[i], len + 1, "%zu: %s", i + 1, lines[i]);
    }
    
    return result;
}

// Don't forget to free the memory when you're done using the result
void freeResult(char** result, size_t count) {
    for (size_t i = 0; i < count; i++) {
        free(result[i]);
    }
    free(result);
}
