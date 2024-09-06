#include <stdio.h>
#include <stdlib.h>

void copy_file(const char *source_path, const char *dest_path) {
    FILE *source = fopen(source_path, "rb");
    if (source == NULL) {
        perror("Error: Cannot open source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest = fopen(dest_path, "wb");
    if (dest == NULL) {
        perror("Error: Cannot open destination file");
        fclose(source);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);
}

int main() {
    const char *source_path = "/path/to/source/file.txt";
    const char *dest_path = "/path/to/dest/tmp_file.txt";

    try {
        copy_file(source_path, dest_path);
        printf("File copied successfully.\n");
    } catch (const std::exception &e) {
        fprintf(stderr, "%s\n", e.what());
    } catch (...) {
        fprintf(stderr, "An unexpected error occurred.\n");
    }

    return 0;
}