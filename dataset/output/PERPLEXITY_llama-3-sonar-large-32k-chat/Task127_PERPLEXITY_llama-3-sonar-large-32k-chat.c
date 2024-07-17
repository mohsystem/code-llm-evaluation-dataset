#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void copyFile(const char* srcDir, const char* srcFile, const char* dstDir) {
    char srcPath[256];
    char dstPath[256];
    sprintf(srcPath, "%s/%s", srcDir, srcFile);
    sprintf(dstPath, "%s/%s", dstDir, srcFile);

    FILE* srcFP = fopen(srcPath, "r");
    if (srcFP == NULL) {
        if (errno == ENOENT) {
            printf("Error: File %s not found in %s
", srcFile, srcDir);
        } else {
            printf("An error occurred: %s
", strerror(errno));
        }
        return;
    }

    FILE* dstFP = fopen(dstPath, "w");
    if (dstFP == NULL) {
        if (errno == EACCES) {
            printf("Error: Permission denied to write to %s
", dstDir);
        } else {
            printf("An error occurred: %s
", strerror(errno));
        }
        fclose(srcFP);
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, 1024, srcFP)) > 0) {
        fwrite(buffer, 1, bytesRead, dstFP);
    }

    fclose(srcFP);
    fclose(dstFP);
    printf("File %s copied successfully to %s
", srcFile, dstDir);
}

int main() {
    const char* srcDir = "/path/to/source/directory";
    const char* srcFile = "file.txt";
    const char* dstDir = "/path/to/temporary/directory";
    copyFile(srcDir, srcFile, dstDir);
    return 0;
}