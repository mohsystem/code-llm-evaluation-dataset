#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 1024

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    char *matrix[MAX_NUM_COLUMNS][MAX_NUM_COLUMNS];
    int num_rows = 0;
    int num_cols = 0;
    int i, j;

    // Open the file for reading
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Tokenize the line by space
        token = strtok(line, " ");
        num_cols = 0;
        while (token != NULL) {
            // Allocate memory for the token and copy it
            matrix[num_rows][num_cols] = malloc(strlen(token) + 1);
            strcpy(matrix[num_rows][num_cols], token);

            // Get the next token
            token = strtok(NULL, " ");
            num_cols++;
        }
        num_rows++;
    }

    // Close the file
    fclose(fp);

    // Print the transposed matrix
    for (j = 0; j < num_cols; j++) {
        for (i = 0; i < num_rows; i++) {
            printf("%s ", matrix[i][j]);
        }
        printf("
");
    }

    // Free the allocated memory
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            free(matrix[i][j]);
        }
    }

    return 0;
}