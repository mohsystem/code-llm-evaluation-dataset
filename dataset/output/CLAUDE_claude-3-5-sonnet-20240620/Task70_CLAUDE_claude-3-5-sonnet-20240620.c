
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\
", argv[0]);
        return 1;
    }

    const char *filePath = argv[1];
    FILE *file = fopen(filePath, "r");

    if (file == NULL) {
        printf("Error opening file: %s\
", filePath);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
