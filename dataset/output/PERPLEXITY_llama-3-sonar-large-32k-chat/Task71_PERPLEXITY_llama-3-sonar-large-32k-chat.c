#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("No input provided. Please provide a command line argument.\n");
        return 1;
    }
    char* endptr;
    errno = 0;
    long num = strtol(argv[1], &endptr, 10);
    if (errno == ERANGE || errno == EINVAL || *endptr != '\0') {
        printf("Invalid input. Please enter a valid integer.\n");
    } else {
        printf("The integer value is: %ld\n", num);
    }
    return 0;
}