#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processFile(const char* sourceFilePath) {
    FILE *sourceFile, *tempFile;
    char ch;
    char tempFilePath[] = "tempXXXXXX"; 

    // Create a temporary file
    int tempFileDescriptor = mkstemp(tempFilePath);
    if (tempFileDescriptor == -1) {
        fprintf(stderr, "Error: Could not create temporary file\n");
        return;
    }

    sourceFile = fopen(sourceFilePath, "rb");
    if (sourceFile == NULL) {
        fprintf(stderr, "Error: File not found at %s\n", sourceFilePath);
        return;
    }

    tempFile = fdopen(tempFileDescriptor, "wb");
    if (tempFile == NULL) {
        fprintf(stderr, "Error: Could not open temporary file\n");
        fclose(sourceFile); 
        return;
    }

    // Copy contents
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, tempFile);
    }

    // Close files
    fclose(sourceFile);
    fclose(tempFile);

    printf("File copied successfully to: %s\n", tempFilePath);
}

int main() {
    const char* sourceFilePath = "/path/to/your/source/file";
    processFile(sourceFilePath);
    return 0;
}