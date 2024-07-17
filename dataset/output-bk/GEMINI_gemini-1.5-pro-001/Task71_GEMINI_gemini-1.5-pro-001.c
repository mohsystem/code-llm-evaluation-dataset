#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an argument.
");
        return 1;
    }

    int number;
    if (sscanf(argv[1], "%d", &number) != 1) {
        printf("Invalid input. Please enter a valid integer.
");
        return 1;
    }

    printf("The integer value is: %d
", number);
    return 0;
}