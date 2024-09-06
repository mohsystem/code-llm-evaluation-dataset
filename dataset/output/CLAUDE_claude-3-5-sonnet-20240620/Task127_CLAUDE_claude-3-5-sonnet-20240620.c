
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#define mkdir(path, mode) _mkdir(path)
#else
#include <unistd.h>
#endif

#define MAX_PATH 1024

void copyFile(const char* sourcePath, const char* destPath) {
    FILE *source, *dest;
    char ch;

    source = fopen(sourcePath, "rb");
    if (source == NULL) {
        fprintf(stderr, "Error: Source file %s not found.\\n", sourcePath);
        return;
    }

    dest = fopen(destPath, "wb");
    if (dest == NULL) {
        fprintf(stderr, "Error: Cannot create destination file %s.\\n", destPath);
        fclose(source);
        return;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    fclose(source);
    fclose(dest);

    printf("File copied successfully from %s to %s\\n", sourcePath, destPath);
}

int main() {
    const char* sourceFile = "source.txt";
    const char* tempDir = "temp";
    char tempFile[MAX_PATH];
    snprintf(tempFile, sizeof(tempFile), "%s/temp_copy.txt", tempDir);

    if (mkdir(tempDir, 0777) == -1) {
        if (errno != EEXIST) {
            fprintf(stderr, "Error creating temporary directory: %s\\n", strerror(errno));
            return 1;
        }
    }

    copyFile(sourceFile, tempFile);

    if (remove(tempFile) == 0) {
        printf("Temporary file %s removed.\\n", tempFile);
    } else {
        fprintf(stderr, "Error removing temporary file: %s\\n", strerror(errno));
    }

    #ifdef _WIN32
    if (_rmdir(tempDir) == 0) {
    #else
    if (rmdir(tempDir) == 0) {
    #endif
        printf("Temporary directory %s removed.\\n", tempDir);
    } else {
        fprintf(stderr, "Error removing temporary directory: %s\\n", strerror(errno));
    }

    return 0;
}
