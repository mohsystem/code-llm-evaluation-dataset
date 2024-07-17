#include <stdio.h>
#include <stdlib.h>

int main() {
    char sourcePath[] = "source.txt";
    char destinationPath[] = "/tmp/destination.txt";

    FILE *sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        perror("The source file does not exist.");
        return 1;
    }

    FILE *destinationFile = fopen(destinationPath, "w");
    if (destinationFile == NULL) {
        perror("An error occurred while opening the destination file.");
        fclose(sourceFile);
        return 1;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        if (fwrite(buffer, 1, bytes, destinationFile) != bytes) {
            perror("An error occurred while writing to the destination file.");
            fclose(sourceFile);
            fclose(destinationFile);
            return 1;
        }
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully in C!
");

    return 0;
}