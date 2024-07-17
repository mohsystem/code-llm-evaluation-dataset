#include <stdio.h>
#include <stdlib.h>

int main() {
    // Get user input
    char userInput[100];
    printf("Enter data for OS command: ");
    fgets(userInput, sizeof(userInput), stdin);

    // Remove newline character from user input
    if (userInput[strlen(userInput) - 1] == '
') {
        userInput[strlen(userInput) - 1] = '\0';
    }

    // Run OS command with user input
    char command[150];
    sprintf(command, "your_command %s", userInput);
    system(command);

    return 0;
}