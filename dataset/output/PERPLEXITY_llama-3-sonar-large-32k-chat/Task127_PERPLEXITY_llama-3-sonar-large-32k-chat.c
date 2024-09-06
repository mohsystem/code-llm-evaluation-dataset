#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char srcDir[] = "/path/to/source/directory";
    char dstDir[] = "/path/to/temporary/directory";
    char filename[] = "file.txt";

    FILE *srcFile = fopen(strcat(srcDir, "/"), "rb");
    FILE *dstFile = fopen(strcat(dstDir, "/"), "wb");

    if (!srcFile) {
        fprintf(stderr, "Error: File %s not found in %s\n", filename, srcDir);
        return 1;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, 1024, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, dstFile);
    }

    fclose(srcFile);
    fclose(dstFile);

    printf("File %s has been copied to %s\n", filename, dstDir);

    return 0;
}