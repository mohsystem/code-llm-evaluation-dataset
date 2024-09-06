
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int convertToInt(const char* input, int* result) {
    char* endptr;
    long value = strtol(input, &endptr, 10);

    if (errno == ERANGE || value > INT_MAX || value < INT_MIN) {
        return 0;
    }

    if (*endptr != '\\0') {
        return 0;
    }

    *result = (int)value;
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\\n", argv[0]);
        return 1;
    }

    int result;
    if (convertToInt(argv[1], &result)) {
        printf("Converted integer: %d\\n", result);
    } else {
        printf("Invalid input: Cannot convert to integer\\n");
    }

    return 0;
}
