#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[20];
    int number;
    printf("Enter a number: ");
    while (1) {
        if (fgets(input, sizeof(input), stdin) != NULL) {
            char *endptr;
            number = strtol(input, &endptr, 10);
            if (endptr != input && *endptr == '\n') break;
        }
        printf("Invalid input. Please enter a number.\n");
    }
    
    printf("You entered: %d\n", number);

    int squared = number * number;
    printf("Square of the number: %d\n", squared);

    return 0;
}