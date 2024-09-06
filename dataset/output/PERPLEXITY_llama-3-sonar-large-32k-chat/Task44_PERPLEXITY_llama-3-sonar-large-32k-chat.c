#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* getUserInput(const char* prompt) {
    char inputStr[256];
    while (true) {
        printf("%s", prompt);
        if (fgets(inputStr, 256, stdin) != NULL) {
            inputStr[strcspn(inputStr, "\n")] = 0; // remove the newline character
            return strdup(inputStr);
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

void validateInput(const char* inputStr) {
    for (int i = 0; inputStr[i] != '\0'; i++) {
        if (!isalpha(inputStr[i])) {
            fprintf(stderr, "Input should only contain alphabets\n");
            exit(1);
        }
    }
}

int main() {
    char* inputStr = getUserInput("Enter a string: ");
    validateInput(inputStr);
    printf("Input is valid\n");
    for (int i = 0; inputStr[i] != '\0'; i++) {
        inputStr[i] = toupper(inputStr[i]);
    }
    printf("Upper case: %s\n", inputStr);
    for (int i = 0; inputStr[i] != '\0'; i++) {
        inputStr[i] = tolower(inputStr[i]);
    }
    printf("Lower case: %s\n", inputStr);
    free(inputStr);
    return 0;
}