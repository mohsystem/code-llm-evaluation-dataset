
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void copyFile(const char* sourcePath, const char* destPath) {
    FILE *source, *dest;
    char ch;

    source = fopen(sourcePath, "rb");
    if (source == NULL) {
        fprintf(stderr, "Error: Cannot open source file %s: %s\
", sourcePath, strerror(errno));
        return;
    }

    dest = fopen(destPath, "wb");
    if (dest == NULL) {
        fprintf(stderr, "Error: Cannot create destination file %s: %s\
", destPath, strerror(errno));
        fclose(source);
        return;
    }

    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, dest) == EOF) {
            fprintf(stderr, "Error: Failed to write to destination file: %s\
", strerror(errno));
            fclose(source);
            fclose(dest);
            return;
        }
    }

    if (ferror(source)) {
        fprintf(stderr, "Error: Failed to read from source file: %s\
", strerror(errno));
    } else {
        printf("File copied successfully from %s to %s\
", sourcePath, destPath);
    }

    fclose(source);
    fclose(dest);
}

int main() {
    const char* sourcePath = "path/to/source/file.txt";
    const char* destPath = "/tmp/copied_file.txt";
    copyFile(sourcePath, destPath);
    return 0;
}
