#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];

    if (remove(file_path) == 0) {
        printf("%s deleted successfully.\n", file_path);
    } else {
        perror("Error");
    }

    return 0;
}