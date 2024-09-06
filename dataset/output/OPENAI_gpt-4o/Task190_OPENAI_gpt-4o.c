#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

int main() {
    FILE *file = fopen("file.txt", "r");
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int num_lines = 0;

    while (fgets(lines[num_lines], MAX_LINE_LENGTH, file)) {
        char *pos;
        if ((pos=strchr(lines[num_lines], '\n')) != NULL) {
            *pos = '\0';
        }
        num_lines++;
    }
    fclose(file);

    char *words[MAX_LINES][MAX_LINE_LENGTH];
    int num_words[MAX_LINES] = {0};
    for (int i = 0; i < num_lines; i++) {
        char *token = strtok(lines[i], " ");
        while (token != NULL) {
            words[i][num_words[i]++] = token;
            token = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < num_words[0]; i++) {
        for (int j = 0; j < num_lines; j++) {
            printf("%s", words[j][i]);
            if (j < num_lines - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}