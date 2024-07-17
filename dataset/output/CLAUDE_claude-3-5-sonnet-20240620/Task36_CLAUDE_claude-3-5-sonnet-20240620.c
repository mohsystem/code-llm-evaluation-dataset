
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME 100
#define MAX_LINE 1000

int main() {
    char filename[MAX_FILENAME];
    char line[MAX_LINE];
    FILE *file;

    printf("Enter the file name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\
")] = 0;  // Remove newline

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\
");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
