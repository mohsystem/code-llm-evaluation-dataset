#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateCommand(const char* command) {
    // Add your validation logic here
    return 1;
}

char* executeCommand(const char* command) {
    char cmd[256];
    sprintf(cmd, "bash -c \"%s\"", command);
    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        return "Error: unable to open pipe";
    }
    char buffer[128];
    char* result = malloc(1024);
    result[0] = '\0';
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL) {
            strcat(result, buffer);
        }
    }
    pclose(pipe);
    return result;
}

int main() {
    printf("Enter a bash shell command: ");
    char command[256];
    fgets(command, 256, stdin);
    command[strcspn(command, "\n")] = 0; // remove newline character
    if (validateCommand(command)) {
        char* result = executeCommand(command);
        printf("%s", result);
        free(result);
    } else {
        printf("Invalid command format or content");
    }
    return 0;
}