
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int validateInput(const char* input) {
    while (*input) {
        if (!isalnum(*input) && !isspace(*input)) {
            return 0;
        }
        input++;
    }
    return 1;
}

void processInput(char* input) {
    while (*input) {
        *input = toupper(*input);
        input++;
    }
}

int main() {
    char userInput[MAX_INPUT_LENGTH];

    while (1) {
        printf("Enter some text (alphanumeric characters and spaces only): ");
        fgets(userInput, sizeof(userInput), stdin);

        // Remove newline character
        userInput[strcspn(userInput, "\\n")] = 0;

        if (validateInput(userInput)) {
            processInput(userInput);
            printf("Processed input: %s\\n", userInput);
            break;
        } else {
            printf("Invalid input. Please try again.\\n");
        }
    }

    return 0;
}
