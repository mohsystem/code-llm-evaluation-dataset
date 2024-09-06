// C
#include <stdio.h>
#include <stdlib.h>

int main() {
    char fileName[100];
    printf("Enter file name: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = 0;  // Remove trailing newline

    FILE *file = fopen(fileName, "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Unable to open file");
    }

    return 0;
}