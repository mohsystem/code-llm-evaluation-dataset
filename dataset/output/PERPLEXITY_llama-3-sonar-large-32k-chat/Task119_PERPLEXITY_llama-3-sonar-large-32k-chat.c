#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DELIMITER ","

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return(-1);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        char *token = strtok(buffer, DELIMITER);
        while (token != NULL) {
            printf("%s
", token);
            token = strtok(NULL, DELIMITER);
        }
    }

    fclose(fp);
    return 0;
}