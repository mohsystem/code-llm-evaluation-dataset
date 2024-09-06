
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\\n", argv[0]);
        return 1;
    }

    const char *filePath = argv[1];

    if (remove(filePath) == 0) {
        printf("File '%s' has been deleted successfully.\\n", filePath);
    } else {
        perror("Error");
        printf("Unable to delete '%s'.\\n", filePath);
    }

    return 0;
}
