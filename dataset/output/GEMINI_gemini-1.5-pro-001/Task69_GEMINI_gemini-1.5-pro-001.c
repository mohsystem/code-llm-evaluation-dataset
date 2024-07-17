#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: File path not provided.
");
        return 1;
    }

    char *filePath = argv[1];

    if (remove(filePath) == 0) {
        printf("File deleted successfully.
");
    } else {
        fprintf(stderr, "Failed to delete the file. File may not exist.
");
        return 1;
    }

    return 0;
}