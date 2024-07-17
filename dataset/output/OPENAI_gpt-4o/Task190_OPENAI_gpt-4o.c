#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 100

void transposeFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE_LENGTH];
    char *lines[MAX_WORDS][MAX_WORDS];
    int rowCount = 0, colCount = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        int col = 0;
        char *word = strtok(buffer, " 
");
        while (word != NULL) {
            lines[rowCount][col] = strdup(word);
            word = strtok(NULL, " 
");
            col++;
        }
        colCount = col; // assuming all rows have same columns
        rowCount++;
    }
    fclose(file);

    for (int i = 0; i < colCount; i++) {
        for (int j = 0; j < rowCount; j++) {
            printf("%s ", lines[j][i]);
            free(lines[j][i]);
        }
        printf("
");
    }
}

int main() {
    transposeFile("file.txt");
    return 0;
}