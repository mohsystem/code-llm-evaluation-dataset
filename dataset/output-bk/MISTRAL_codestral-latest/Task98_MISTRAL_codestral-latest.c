#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[256];
    char *end;
    long number;

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    number = strtol(input, &end, 10);

    if (end == input || *end != '
') {
        printf("Invalid input. Please enter a valid integer.
");
    } else {
        printf("You entered: %ld
", number);
    }

    return 0;
}