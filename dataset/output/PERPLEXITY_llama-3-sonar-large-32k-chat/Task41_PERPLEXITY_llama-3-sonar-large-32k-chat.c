code here:
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char userInput[BUFFER_SIZE];
    printf("Enter a string: ");
    fgets(userInput, BUFFER_SIZE, stdin);
    userInput[strcspn(userInput, "\n")] = 0; // remove newline character
    printf("You entered: %s\n", userInput);
    return 0;
}