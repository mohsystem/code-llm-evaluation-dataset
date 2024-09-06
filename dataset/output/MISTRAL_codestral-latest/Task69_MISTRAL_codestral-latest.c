#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc > 1) {
        const char* filePath = argv[1];

        if (remove(filePath) == 0) {
            printf("File %s has been deleted.\n", filePath);
        } else {
            printf("Failed to delete the file.\n");
        }
    } else {
        printf("Please provide the file path as a command line argument.\n");
    }

    return 0;
}