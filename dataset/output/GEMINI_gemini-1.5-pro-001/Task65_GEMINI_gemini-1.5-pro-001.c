#include <stdio.h>
#include <stdlib.h>

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return NULL;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for file content
    char *content = (char *)malloc(file_size + 1);
    if (content == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(file);
        return NULL;
    }

    // Read file content
    size_t result = fread(content, 1, file_size, file);
    if (result != file_size) {
        fprintf(stderr, "Error reading file '%s'\n", filename);
        fclose(file);
        free(content);
        return NULL;
    }

    content[file_size] = '\0';
    fclose(file);
    return content;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *file_content = read_file(filename);

    if (file_content != NULL) {
        printf("%s", file_content);
        free(file_content);
    }

    return 0;
}