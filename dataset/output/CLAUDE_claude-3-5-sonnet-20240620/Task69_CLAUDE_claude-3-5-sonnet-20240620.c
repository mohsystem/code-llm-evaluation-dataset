
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\
", argv[0]);
        return 1;
    }

    const char *filePath = argv[1];

    if (remove(filePath) == 0) {
        printf("File deleted successfully: %s\
", filePath);
    } else {
        printf("Failed to delete the file: %s\
", filePath);
    }

    return 0;
}
