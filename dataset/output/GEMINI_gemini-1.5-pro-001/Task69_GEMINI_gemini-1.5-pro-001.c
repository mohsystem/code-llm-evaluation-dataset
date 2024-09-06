#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: delete_file <file_path>\n");
        return 1;
    }

    char *file_path = argv[1];

    if (remove(file_path) == 0) {
        printf("File '%s' deleted successfully.\n", file_path);
    } else {
        perror("Error deleting file");
        return 1;
    }

    return 0;
}