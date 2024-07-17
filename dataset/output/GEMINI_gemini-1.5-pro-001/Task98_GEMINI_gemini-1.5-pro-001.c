#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int number;

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    number = atoi(input);

    printf("You entered: %d
", number);

    return 0;
}