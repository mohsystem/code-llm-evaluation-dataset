// C
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char concatenatedString[MAX_LENGTH] = "";
    char userInput[MAX_LENGTH];

    while (1) {
        printf("Enter a string (or press enter to finish): ");
        fgets(userInput, MAX_LENGTH, stdin);
        userInput[strcspn(userInput, "\n")] = 0; // Remove trailing newline
        if (strlen(userInput) == 0) {
            break;
        }
        strcat(concatenatedString, userInput);
    }

    printf("Concatenated string: %s\n", concatenatedString);

    return 0;
}