#include <stdio.h>
#include <stdlib.h>

int main() {
    char userInput[50];
    printf("Enter a number: ");
    if (fgets(userInput, 50, stdin) != NULL) {
        char *end;
        long result = strtol(userInput, &end, 10);
        if (end != userInput && *end == '\n') {
            printf("Converted Integer: %ld\n", result);
        } else {
            printf("Error: Not a valid integer\n");
        }
    }
    return 0;
}