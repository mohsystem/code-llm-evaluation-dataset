// C
#include <stdio.h>
#include <stdlib.h>

int main() {
    char userInput[256];
    int num;
    char *end;

    printf("Enter a number: ");
    fgets(userInput, sizeof(userInput), stdin);

    num = strtol(userInput, &end, 10);

    if (end == userInput || *end != '\n') {
        printf("Invalid input. Please enter an integer.\n");
    } else {
        printf("You entered: %d\n", num);
    }

    return 0;
}