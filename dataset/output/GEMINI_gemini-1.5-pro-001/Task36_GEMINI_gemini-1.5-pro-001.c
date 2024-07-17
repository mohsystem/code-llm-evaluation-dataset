#include <stdio.h>
#include <stdlib.h>

int main() {
    char filePath[100];
    FILE *file;

    printf("Enter the file path: ");
    scanf("%s", filePath);

    file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char character;
    while ((character = fgetc(file)) != EOF) {
        putchar(character);
    }

    fclose(file);
    return 0;
}