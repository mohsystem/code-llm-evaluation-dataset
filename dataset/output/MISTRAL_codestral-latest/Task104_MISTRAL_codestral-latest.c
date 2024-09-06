// C
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    char userInput[BUFFER_SIZE + 1];
    printf("Enter a string: ");
    fgets(userInput, BUFFER_SIZE + 1, stdin);
    if (strlen(userInput) > BUFFER_SIZE) {
        userInput[BUFFER_SIZE] = '\0';
    }
    printf("Truncated input: %s", userInput);
    return 0;
}