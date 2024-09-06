#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filePath[256];
    FILE *file;
    long fileSize;
    char *buffer;
    size_t bytesRead;

    printf("Enter the path to the file you want to upload: ");
    fgets(filePath, sizeof(filePath), stdin);
    filePath[strcspn(filePath, "\n")] = '\0';  // Remove newline

    file = fopen(filePath, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filePath);
        return 1;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    // Allocate memory for the file content
    buffer = (char *)malloc(fileSize + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read the file content into the buffer
    bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        fprintf(stderr, "Error reading file.\n");
        fclose(file);
        free(buffer);
        return 1;
    }
    buffer[fileSize] = '\0';  // Null-terminate the buffer

    fclose(file);

    // Process the uploaded file content (buffer) here
    // ...

    free(buffer);

    printf("File uploaded successfully!\n");

    return 0;
}