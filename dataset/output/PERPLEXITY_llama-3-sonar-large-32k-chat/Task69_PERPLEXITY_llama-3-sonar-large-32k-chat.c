#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./delete_file <file_path>\n");
        return 1;
    }

    char* filePath = argv[1];

    if (remove(filePath) != 0) {
        printf("Failed to delete the file\n");
    } else {
        printf("File deleted successfully\n");
    }

    return 0;
}