
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char userInput[MAX_INPUT_LENGTH];
    char *endptr;
    
    printf("Enter a number: ");
    fgets(userInput, sizeof(userInput), stdin);
    
    // Remove newline character if present
    userInput[strcspn(userInput, "\\n")] = 0;
    
    long number = strtol(userInput, &endptr, 10);
    
    if (*endptr == '\\0') {
        printf("Successfully converted to integer: %ld\\n", number);
    } else {
        printf("Invalid input. Please enter a valid integer.\\n");
    }
    
    return 0;
}
