#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** number(const char* const* lines, size_t size) {
    char** numberedLines = malloc(size * sizeof(char*));
    for (size_t i = 0; i < size; i++) {
        char buffer[12];
        sprintf(buffer, "%zu: ", i + 1);
        size_t len = strlen(buffer) + strlen(lines[i]) + 1;
        numberedLines[i] = malloc(len * sizeof(char));
        strcpy(numberedLines[i], buffer);
        strcat(numberedLines[i], lines[i]);
    }
    return numberedLines;
}