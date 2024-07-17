#include <stdio.h>

int main() {
    char filePath[100];
    printf("Enter the file path: ");
    scanf("%s", filePath);

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return(-1);
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
    return 0;
}