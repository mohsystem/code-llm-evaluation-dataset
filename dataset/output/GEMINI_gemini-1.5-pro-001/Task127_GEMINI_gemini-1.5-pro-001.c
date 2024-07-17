#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char* temp_filename = "temp.txt";
    FILE *source_file, *temp_file;
    char ch;

    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open source file in read mode
    source_file = fopen(filename, "r");
    if (source_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s.
", filename);
        return 1;
    }

    // Open temporary file in write mode
    temp_file = fopen(temp_filename, "w");
    if (temp_file == NULL) {
        fclose(source_file);
        fprintf(stderr, "Error: Could not create temporary file.
");
        return 1;
    }

    // Copy contents to temporary file
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, temp_file);
    }

    // Close files
    fclose(source_file);
    fclose(temp_file);

    printf("File copied to temporary location: %s
", temp_filename);
    return 0;
}