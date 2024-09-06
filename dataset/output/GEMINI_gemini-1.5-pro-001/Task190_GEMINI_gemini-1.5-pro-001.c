#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_WORDS 100

int main() {
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *words[MAX_NUM_WORDS];
    int num_rows = 0;
    int num_cols = 0;

    // Read file and store words in a 2D array
    while (fgets(line, sizeof(line), fp) != NULL) {
        int i = 0;
        char *token = strtok(line, " \n");
        while (token != NULL) {
            words[num_rows * MAX_NUM_WORDS + i] = strdup(token);
            token = strtok(NULL, " \n");
            i++;
        }
        num_cols = i;
        num_rows++;
    }

    // Transpose and print the 2D array
    for (int i = 0; i < num_cols; i++) {
        for (int j = 0; j < num_rows; j++) {
            printf("%s ", words[j * MAX_NUM_WORDS + i]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < num_rows * num_cols; i++) {
        free(words[i]);
    }

    fclose(fp);
    return 0;
}