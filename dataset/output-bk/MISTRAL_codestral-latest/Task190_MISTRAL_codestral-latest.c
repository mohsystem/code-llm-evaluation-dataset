#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORDS_PER_LINE 100

int main() {
    FILE *file = fopen("file.txt", "r");
    char lines[MAX_WORDS_PER_LINE][MAX_LINE_LENGTH];
    int line_count = 0;
    int word_count = 0;

    while (fgets(lines[line_count], MAX_LINE_LENGTH, file)) {
        char *token = strtok(lines[line_count], " ");
        word_count = 0;
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " ");
        }
        line_count++;
    }

    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < line_count; j++) {
            char *token = strtok(j == 0 ? lines[j] : NULL, " ");
            for (int k = 0; k < i; k++) {
                token = strtok(NULL, " ");
            }
            printf("%s ", token);
        }
        printf("
");
    }

    fclose(file);
    return 0;
}