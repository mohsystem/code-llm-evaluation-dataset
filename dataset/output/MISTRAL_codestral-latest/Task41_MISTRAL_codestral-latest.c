// C
#include <stdio.h>
#include <stdlib.h>

void processString(char* inputString) {
    // Process the string here
    printf("Processed string: %s\n", inputString);
}

int main() {
    char* inputString = NULL;
    size_t size = 0;

    printf("Enter a string: ");
    getline(&inputString, &size, stdin);

    processString(inputString);

    free(inputString);
    return 0;
}

// C is not safe from buffer overflow by default. However, getline() function is used which reads a line from stream and resizes the buffer as needed.