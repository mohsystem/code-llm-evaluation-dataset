
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

int divide(int a, int b) {
    if (b == 0) {
        errno = EDOM;
        return 0;
    }
    return a / b;
}

int main() {
    char input[100];
    int num, divisor, result, index;
    int array[5] = {0};

    printf("Enter a number: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\
");
        return 1;
    }

    errno = 0;
    char *endptr;
    long l = strtol(input, &endptr, 10);
    if (errno != 0 || *endptr != \'\
\' || l > INT_MAX || l < INT_MIN) {
        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\
");
        return 1;
    }
    num = (int)l;

    printf("Enter another number: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\
");
        return 1;
    }

    errno = 0;
    l = strtol(input, &endptr, 10);
    if (errno != 0 || *endptr != \'\
\' || l > INT_MAX || l < INT_MIN) {
        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\
");
        return 1;
    }
    divisor = (int)l;

    result = divide(num, divisor);
    if (errno == EDOM) {
        fprintf(stderr, "Error: Division by zero is not allowed.\
");
        return 1;
    }
    printf("Result of division: %d\
", result);

    printf("Enter an index to access the array: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\
");
        return 1;
    }

    errno = 0;
    l = strtol(input, &endptr, 10);
    if (errno != 0 || *endptr != \'\
\' || l > INT_MAX || l < INT_MIN) {
        fprintf(stderr, "Error: Invalid input. Please enter a valid integer.\
");
        return 1;
    }
    index = (int)l;

    if (index < 0 || index >= 5) {
        fprintf(stderr, "Error: Array index out of bounds.\
");
        return 1;
    }

    printf("Value at index %d: %d\
", index, array[index]);

    return 0;
}
