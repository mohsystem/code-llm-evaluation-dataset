
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

double divide_numbers(double a, double b) {
    if (b == 0) {
        errno = EDOM;
        return 0;
    }
    return a / b;
}

int main() {
    char input[100];
    double num1, num2, result;

    printf("Enter first number: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\\n");
        return 1;
    }

    errno = 0;
    char *endptr;
    num1 = strtod(input, &endptr);
    if (errno != 0 || *endptr != '\\n') {
        fprintf(stderr, "Error: Invalid input for first number\\n");
        return 1;
    }

    printf("Enter second number: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\\n");
        return 1;
    }

    errno = 0;
    num2 = strtod(input, &endptr);
    if (errno != 0 || *endptr != '\\n') {
        fprintf(stderr, "Error: Invalid input for second number\\n");
        return 1;
    }

    result = divide_numbers(num1, num2);
    if (errno == EDOM) {
        fprintf(stderr, "Error: Cannot divide by zero\\n");
    } else {
        printf("Result: %f\\n", result);
    }

    printf("Program execution completed.\\n");
    return 0;
}
