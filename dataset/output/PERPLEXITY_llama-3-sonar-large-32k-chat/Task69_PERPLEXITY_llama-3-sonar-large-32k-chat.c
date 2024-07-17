#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>
", argv[0]);
        return 1;
    }
    if (remove(argv[1]) == 0) {
        printf("File deleted successfully
");
    } else {
        printf("Failed to delete the file
");
    }
    return 0;
}