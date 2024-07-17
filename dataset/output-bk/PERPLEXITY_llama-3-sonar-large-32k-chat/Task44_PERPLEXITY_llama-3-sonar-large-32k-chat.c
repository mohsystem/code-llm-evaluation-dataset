#include <stdio.h>

int main() {
    int num1, num2;

    while (1) {
        printf("Enter first number: ");
        if (scanf("%d", &num1) == 1) {
            break;
        } else {
            printf("Invalid input. Please enter a valid number.
");
            int c;
            while ((c = getchar()) != '
' && c != EOF);
        }
    }

    while (1) {
        printf("Enter second number: ");
        if (scanf("%d", &num2) == 1) {
            break;
        } else {
            printf("Invalid input. Please enter a valid number.
");
            int c;
            while ((c = getchar()) != '
' && c != EOF);
        }
    }

    printf("Sum: %d
", num1 + num2);
    printf("Difference: %d
", num1 - num2);
    printf("Product: %d
", num1 * num2);
    if (num2 != 0) {
        printf("Quotient: %d
", num1 / num2);
    } else {
        printf("Cannot divide by zero.
");
    }

    return 0;
}