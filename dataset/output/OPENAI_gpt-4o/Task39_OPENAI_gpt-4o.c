#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[256];
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove newline character
    #ifdef _WIN32
        char command[512];
        snprintf(command, sizeof(command), "type %s", filename);
    #else
        char command[512];
        snprintf(command, sizeof(command), "cat %s", filename);
    #endif
    system(command);
    return 0;
}