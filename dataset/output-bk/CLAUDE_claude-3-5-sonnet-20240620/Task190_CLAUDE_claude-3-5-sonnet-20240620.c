
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LINE_LENGTH 1000

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error opening file\
");
        return 1;
    }

    char data[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH];
    int rows = 0, cols = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \
");
        cols = 0;
        while (token != NULL) {
            strcpy(data[rows][cols], token);
            token = strtok(NULL, " \
");
            cols++;
        }
        rows++;
    }
    fclose(file);

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            printf("%s", data[i][j]);
            if (i < rows - 1) printf(" ");
        }
        printf("\
");
    }

    return 0;
}
