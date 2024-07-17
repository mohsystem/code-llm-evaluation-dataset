#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;

    printf("Enter first number: ");
    if (scanf("%d", &num1) != 1) {
        printf("Invalid input. Please enter numbers only.
");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%d", &num2) != 1) {
        printf("Invalid input. Please enter numbers only.
");
        return 1;
    }

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;

    printf("Sum: %d
", sum);
    printf("Difference: %d
", difference);
    printf("Product: %d
", product);

    if (num2 == 0) {
        printf("Cannot divide by zero.
");
    } else {
        double quotient = (double)num1 / num2;
        printf("Quotient: %f
", quotient);
    }

    return 0;
}