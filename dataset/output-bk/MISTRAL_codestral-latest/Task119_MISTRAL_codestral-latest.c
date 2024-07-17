// C
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file = fopen("file.csv", "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            // Process token here
            token = strtok(NULL, ",");
        }
    }
    fclose(file);
    return 0;
}