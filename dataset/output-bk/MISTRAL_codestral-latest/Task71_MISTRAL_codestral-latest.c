#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *end;
    long num = strtol(argv[1], &end, 10);

    if (*end != '\0' || num < INT_MIN || num > INT_MAX) {
        printf("Invalid input. Please enter an integer.
");
    } else {
        printf("The integer is: %ld
", num);
    }

    return 0;
}