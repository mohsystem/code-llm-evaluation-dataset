#include <stdio.h>
#include <stdlib.h>
int main() {
    char input[256];
    int number;
    printf("Enter a number: ");
    fgets(input, 256, stdin);
    char *endptr;
    number = strtol(input, &endptr, 10);
    if (endptr == input || *endptr != '
') {
        printf("Invalid input. Not an integer.
");
    } else {
        printf("You entered: %d
", number);
    }
    return 0;
}