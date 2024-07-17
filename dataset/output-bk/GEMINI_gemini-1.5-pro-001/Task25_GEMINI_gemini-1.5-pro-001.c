#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** number(char ** lines, int lines_size, int* returnSize) {
    char ** numberedLines = malloc(lines_size * sizeof(char *));
    *returnSize = lines_size;
    for (int i = 0; i < lines_size; i++) {
        int lineNumber = i + 1;
        int lineNumberDigits = snprintf(NULL, 0, "%d", lineNumber);
        int lineLength = strlen(lines[i]);
        int totalLength = lineNumberDigits + 2 + lineLength + 1; // +2 for ": ", +1 for null terminator
        numberedLines[i] = malloc(totalLength * sizeof(char));
        sprintf(numberedLines[i], "%d: %s", lineNumber, lines[i]);
    }
    return numberedLines;
}

int main() {
    char *lines[] = {"a", "b", "c"};
    int lines_size = sizeof(lines) / sizeof(lines[0]);
    int returnSize;
    char **result = number(lines, lines_size, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s
", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}