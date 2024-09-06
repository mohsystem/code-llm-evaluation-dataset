#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./file_reader <file_path>\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("File not found\n");
        return 1;
    }
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}