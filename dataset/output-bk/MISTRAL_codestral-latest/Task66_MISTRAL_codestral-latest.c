#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    printf("Enter a shell command:
");
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    // Remove newline character from command
    command[strcspn(command, "
")] = 0;

    int result = system(command);

    if (result == -1) {
        fprintf(stderr, "Error executing command
");
        return 1;
    }

    return 0;
}