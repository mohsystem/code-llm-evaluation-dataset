#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide the file path as an argument.
");
        return 1;
    }
    if (remove(argv[1]) == 0) {
        printf("File deleted successfully.
");
    } else {
        perror("Error deleting the file");
    }
    return 0;
}