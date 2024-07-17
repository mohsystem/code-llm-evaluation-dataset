#include <stdio.h>
#include <string.h>

int main() {
    char fileName[256];
    printf("Enter file name: ");
    fgets(fileName, 256, stdin);
    fileName[strcspn(fileName, "
")] = 0; // remove newline character
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error reading file: %s
", fileName);
        return 1;
    }
    char line[256];
    while (fgets(line, 256, file)) {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}