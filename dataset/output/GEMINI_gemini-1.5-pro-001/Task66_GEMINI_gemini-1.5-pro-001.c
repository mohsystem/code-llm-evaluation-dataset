#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[1024];
    printf("Enter a bash command: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0; // remove trailing newline

    // Execute the command using popen
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error executing command.\n");
        return 1;
    }

    // Read and print the output
    char output[1024];
    while (fgets(output, sizeof(output), fp) != NULL) {
        printf("%s", output);
    }

    // Close the pipe and check for errors
    int status = pclose(fp);
    if (status == -1) {
        fprintf(stderr, "Error closing command stream.\n");
        return 1;
    }

    return 0;
}