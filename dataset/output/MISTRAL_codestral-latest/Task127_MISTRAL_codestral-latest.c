#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* sourceFile = "/path/to/source/file";
    const char* destinationFile = "/path/to/destination/file";

    FILE* source = fopen(sourceFile, "rb");
    FILE* destination = fopen(destinationFile, "wb");

    if (source != NULL && destination != NULL) {
        size_t bytesRead;
        unsigned char buffer[1024];

        while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
            fwrite(buffer, 1, bytesRead, destination);
        }

        printf("File copied successfully.
");
    } else {
        printf("An error occurred.
");
    }

    if (source != NULL) {
        fclose(source);
    }

    if (destination != NULL) {
        fclose(destination);
    }

    return 0;
}