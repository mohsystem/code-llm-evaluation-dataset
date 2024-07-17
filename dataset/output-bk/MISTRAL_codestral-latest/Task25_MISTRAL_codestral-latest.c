#include <stdio.h>
#include <stdlib.h>

char** number(const char* const* lines, size_t length, size_t* newLength) {
    char** numberedLines = malloc(length * sizeof(char*));
    for (size_t i = 0; i < length; i++) {
        char buffer[12];
        sprintf(buffer, "%zu: ", i + 1);
        size_t bufferLength = strlen(buffer);
        size_t lineLength = strlen(lines[i]);
        numberedLines[i] = malloc((bufferLength + lineLength + 1) * sizeof(char));
        strcpy(numberedLines[i], buffer);
        strcpy(numberedLines[i] + bufferLength, lines[i]);
    }
    *newLength = length;
    return numberedLines;
}