#include <stdio.h>
#include <stdlib.h>

int main() {
    // Get user input
    char userInput[100];
    printf("Enter data for OS command: ");
    fgets(userInput, sizeof(userInput), stdin);

    // Construct the OS command
    char command[200];
    sprintf(command, "your_command_here %s", userInput);

    // Execute the command
    system(command);

    return 0;
}