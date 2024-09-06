code here:
#include <stdio.h>

int main() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%99s", filename);
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char line[1000];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Unable to open file");
    }
    return 0;
}