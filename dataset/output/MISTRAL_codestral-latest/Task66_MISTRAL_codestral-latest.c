#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool validateCommand(const char* command) {
    // Simple validation: check if command is not empty
    while (*command != '\0') {
        if (*command != ' ') {
            return true;
        }
        command++;
    }
    return false;
}

int main() {
    char command[256];
    printf("Enter a bash shell command: ");
    fgets(command, sizeof(command), stdin);

    // Remove trailing newline character
    command[strcspn(command, "\n")] = '\0';

    if (validateCommand(command)) {
        FILE* pipe = popen(command, "r");
        if (!pipe) {
            fprintf(stderr, "Error: Failed to execute command\n");
            return 1;
        }

        char buffer[256];
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            printf("%s", buffer);
        }

        pclose(pipe);
    } else {
        printf("Invalid command\n");
    }

    return 0;
}