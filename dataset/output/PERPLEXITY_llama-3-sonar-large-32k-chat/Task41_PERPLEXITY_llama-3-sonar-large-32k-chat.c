#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char input[BUFFER_SIZE];
    printf("Enter a string: ");
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "
")] = 0; // remove newline character
    printf("You entered: %s
", input);
    return 0;
}