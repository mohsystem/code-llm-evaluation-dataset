
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256
#define BUFFER_SIZE 1024

void uploadFile() {
    char filename[MAX_FILENAME];
    printf("Enter the filename to upload: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\\n")] = 0;  // Remove newline

    FILE *file = fopen(filename, "rb");
    if (file) {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);

        char buffer[BUFFER_SIZE];
        size_t bytesRead;
        long totalBytesRead = 0;

        while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            totalBytesRead += bytesRead;
        }

        fclose(file);

        printf("File \'%s\' uploaded successfully.\\n", filename);
        printf("File size: %ld bytes\\n", fileSize);
    } else {
        printf("File \'%s\' not found.\\n", filename);
    }
}

int main() {
    uploadFile();
    return 0;
}
