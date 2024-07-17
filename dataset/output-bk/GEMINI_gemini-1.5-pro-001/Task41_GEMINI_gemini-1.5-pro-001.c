#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char inputString[MAX_INPUT_SIZE];
    
    printf("Enter a string: ");
    fgets(inputString, MAX_INPUT_SIZE, stdin);

    // Remove potential newline character from fgets()
    inputString[strcspn(inputString, "
")] = 0;

    // Allocate memory for processed string dynamically
    char *processedString = malloc(strlen(inputString) + 1);
    if (processedString == NULL) {
        fprintf(stderr, "Memory allocation failed!
");
        return 1;
    }

    // Process the string (example: convert to uppercase)
    for (size_t i = 0; i < strlen(inputString); ++i) {
        processedString[i] = toupper(inputString[i]);
    }
    processedString[strlen(inputString)] = '\0'; 

    printf("Processed string: %s
", processedString);

    free(processedString);
    return 0;
}