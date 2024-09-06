#include <stdio.h>
#include <stdlib.h>

int main() {
    char userInput[100];
    int integerValue;

    printf("Enter an integer: ");
    fgets(userInput, sizeof(userInput), stdin);

    if (sscanf(userInput, "%d", &integerValue) == 1) {
        printf("Successfully converted to integer: %d\n", integerValue);
    } else {
        printf("Invalid input. Please enter a valid integer.\n");
    }

    return 0;
}