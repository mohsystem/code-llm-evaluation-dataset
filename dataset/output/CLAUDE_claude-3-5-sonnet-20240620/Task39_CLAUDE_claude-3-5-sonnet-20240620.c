
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256

int main() {
    char filename[MAX_FILENAME];
    char command[MAX_FILENAME + 5]; // 4 for "cat " and 1 for null terminator

    printf("Enter the filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error reading input\\n");
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(filename);
    if (len > 0 && filename[len-1] == '\\n') {
        filename[len-1] = '\\0';
    }

    snprintf(command, sizeof(command), "cat %s", filename);
    
    int result = system(command);

    if (result != 0) {
        fprintf(stderr, "Error executing command\\n");
        return 1;
    }

    return 0;
}
