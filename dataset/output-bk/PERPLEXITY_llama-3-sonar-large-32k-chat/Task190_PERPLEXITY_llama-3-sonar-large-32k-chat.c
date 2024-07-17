#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("file.txt", "r");
    char line[1024];
    int rows = 0;
    int cols = 0;
    while (fgets(line, 1024, file)) {
        rows++;
        char *token = strtok(line, " ");
        while (token != NULL) {
            cols = cols > 0 ? cols : 1;
            token = strtok(NULL, " ");
        }
    }
    rewind(file);
    char **lines = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        lines[i] = (char *)malloc(1024 * sizeof(char));
        fgets(lines[i], 1024, file);
    }
    fclose(file);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            char *token = strtok(lines[j], " ");
            for (int k = 0; k < i; k++) {
                token = strtok(NULL, " ");
            }
            printf("%s ", token);
        }
        printf("
");
    }
    for (int i = 0; i < rows; i++) {
        free(lines[i]);
    }
    free(lines);
    return 0;
}