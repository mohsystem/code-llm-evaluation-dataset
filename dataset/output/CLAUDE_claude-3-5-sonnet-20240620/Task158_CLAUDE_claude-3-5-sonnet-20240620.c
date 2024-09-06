
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000

int main() {
    char userInput[MAX_INPUT];
    char command[MAX_INPUT + 5];  // Extra space for "echo " and null terminator

    printf("Enter data: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\\n")] = 0;  // Remove newline if present

    snprintf(command, sizeof(command), "echo %s", userInput);
    system(command);

    return 0;
}
