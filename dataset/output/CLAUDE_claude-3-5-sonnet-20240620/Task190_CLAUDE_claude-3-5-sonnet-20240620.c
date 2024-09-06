
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LINE_LENGTH 1000

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error opening file\\n");
        return 1;
    }

    char content[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH];
    int row = 0, col = 0, max_col = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \\n");
        col = 0;
        while (token != NULL) {
            strcpy(content[row][col], token);
            token = strtok(NULL, " \\n");
            col++;
        }
        if (col > max_col) max_col = col;
        row++;
    }
    fclose(file);

    for (int j = 0; j < max_col; j++) {
        for (int i = 0; i < row; i++) {
            printf("%s", content[i][j]);
            if (i < row - 1) printf(" ");
        }
        printf("\\n");
    }

    return 0;
}
