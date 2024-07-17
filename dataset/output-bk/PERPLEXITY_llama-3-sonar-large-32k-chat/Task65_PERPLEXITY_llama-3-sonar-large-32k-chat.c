#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>
", argv[0]);
        return 1;
    }
    char filename[MAX_FILENAME_LENGTH];
    strncpy(filename, argv[1], MAX_FILENAME_LENGTH);
    if (!isValidFilename(filename)) {
        printf("Invalid filename format
");
        return 1;
    }
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File does not exist or is inaccessible
");
        return 1;
    }
    char line[1024];
    while (fgets(line, 1024, file)) {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}

int isValidFilename(char *filename) {
    // Add your filename validation logic here
    return 1;
}