// This task is quite challenging in C, as it doesn't have built-in support for dynamic arrays or strings.
// The code below assumes a maximum number of lines and columns, and a maximum length for each field.
#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 100
#define MAX_FIELD_LENGTH 100

int main() {
    FILE *file = fopen("file.txt", "r");
    char lines[MAX_LINES][MAX_COLS][MAX_FIELD_LENGTH];
    int lineCount = 0;
    char line[MAX_FIELD_LENGTH];
    while (fgets(line, MAX_FIELD_LENGTH, file) != NULL) {
        char *token = strtok(line, " ");
        int colCount = 0;
        while (token != NULL) {
            strcpy(lines[lineCount][colCount], token);
            token = strtok(NULL, " ");
            colCount++;
        }
        lineCount++;
    }
    fclose(file);
    for (int col = 0; col < colCount; col++) {
        for (int line = 0; line < lineCount; line++) {
            printf("%s ", lines[line][col]);
        }
        printf("\n");
    }
    return 0;
}