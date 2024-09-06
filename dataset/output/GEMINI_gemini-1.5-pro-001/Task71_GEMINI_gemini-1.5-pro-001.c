#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an argument to be converted to an integer.\n");
        return 1;
    }

    char *endptr;
    long converted_integer = strtol(argv[1], &endptr, 10);

    if (*endptr == '\0') {
        printf("Successfully converted '%s' to integer: %ld\n", argv[1], converted_integer);
    } else {
        printf("Unable to convert '%s' to an integer.\n", argv[1]);
    }

    return 0;
}