#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100], content[1024];
    FILE *fp;

    printf("Enter the file name: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "
")] = 0; // Remove trailing newline

    printf("Enter the file content (end with EOF): ");
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("No file uploaded
");
        return 1;
    }
    while (fgets(content, 1024, stdin) != NULL) {
        fputs(content, fp);
    }
    fclose(fp);
    printf("File uploaded successfully
");

    return 0;
}