
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char* content = NULL;
    char line[MAX_LINE_LENGTH];
    size_t total_length = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        size_t line_length = strlen(line);
        char* new_content = realloc(content, total_length + line_length + 1);
        if (new_content == NULL) {
            free(content);
            fclose(file);
            return NULL;
        }
        content = new_content;
        strcpy(content + total_length, line);
        total_length += line_length;
    }

    fclose(file);
    return content;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\
", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    char* content = read_file(filename);

    if (content == NULL) {
        printf("Error: Unable to read file \'%s\'\
", filename);
        return 1;
    }

    printf("File content:\
%s", content);
    free(content);
    return 0;
}
