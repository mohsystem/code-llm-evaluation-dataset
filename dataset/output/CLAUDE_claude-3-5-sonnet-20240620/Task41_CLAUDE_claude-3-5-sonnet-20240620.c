
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void processInput(const char* input) {
    // Process the input (example: print it back)
    printf("Processed input: %s\\n", input);
}

int main() {
    char userInput[MAX_LENGTH + 1]; // +1 for null terminator
    printf("Enter a string (max 100 characters): ");
    
    // Read input safely
    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        // Remove newline if present
        size_t len = strlen(userInput);
        if (len > 0 && userInput[len-1] == '\\n') {
            userInput[len-1] = '\\0';
        }
        
        processInput(userInput);
    } else {
        printf("Error reading input.\\n");
    }
    
    return 0;
}
