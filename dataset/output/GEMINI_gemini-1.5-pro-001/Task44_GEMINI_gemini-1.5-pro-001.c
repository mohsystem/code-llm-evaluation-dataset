#include <stdio.h>

int main() {
    int integerInput;
    double doubleInput;

    // Get an integer from the user
    printf("Enter an integer: ");
    while (scanf("%d", &integerInput) != 1 || integerInput <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while (getchar() != '
');  // Clear input buffer
    }

    // Get a double from the user
    printf("Enter a double: ");
    while (scanf("%lf", &doubleInput) != 1 || doubleInput <= 0) {
        printf("Invalid input. Please enter a positive double: ");
        while (getchar() != '
');  // Clear input buffer
    }

    // Perform some operations on the input
    int sum = integerInput + (int)doubleInput;
    double product = integerInput * doubleInput;

    printf("Sum: %d
", sum);
    printf("Product: %lf
", product);

    return 0;
}