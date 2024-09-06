// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define MAX_WORDS_PER_LINE 100

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char lines[MAX_WORDS_PER_LINE][MAX_LINE_LENGTH];
    char *words[MAX_WORDS_PER_LINE][MAX_WORDS_PER_LINE];
    int num_lines = 0, num_words = 0;

    while (fgets(lines[num_lines], MAX_LINE_LENGTH, file)) {
        char *token = strtok(lines[num_lines], " ");
        int word_index = 0;
        while (token != NULL) {
            words[num_lines][word_index] = strdup(token);
            token = strtok(NULL, " ");
            word_index++;
        }
        num_words = word_index;
        num_lines++;
    }
    fclose(file);

    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < num_lines; j++) {
            printf("%s ", words[j][i]);
        }
        printf("\n");
    }

    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < num_words; j++) {
            free(words[i][j]);
        }
    }

    return 0;
}