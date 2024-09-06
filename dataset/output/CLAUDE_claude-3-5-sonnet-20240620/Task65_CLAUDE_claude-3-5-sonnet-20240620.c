
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(const char* filename) {
    if (strlen(filename) < 4 || strcmp(filename + strlen(filename) - 4, ".txt") != 0) {
        printf("Error: File must have a .txt extension\\n");
        return;
    }

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\\n", filename);
        return;
    }

    printf("File contents:\\n");
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\\n", argv[0]);
    } else {
        read_file(argv[1]);
    }
    return 0;
}
