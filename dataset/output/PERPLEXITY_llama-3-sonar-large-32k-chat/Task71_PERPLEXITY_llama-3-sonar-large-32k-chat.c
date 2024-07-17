#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char *endptr;
        int num = strtol(argv[1], &endptr, 10);
        if (endptr == argv[1]) {
            printf("Invalid input. Please enter a valid integer.
");
        } else {
            printf("The integer value is: %d
", num);
        }
    } else {
        printf("No input provided.
");
    }
    return 0;
}