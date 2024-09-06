
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

void readFile(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error opening file: %s\\n", filePath);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\\n", argv[0]);
        return 1;
    }

    const char* filePath = argv[1];
    readFile(filePath);

    return 0;
}
