#include <stdio.h>

int main() {
    double x, y;
    char op;

    printf("Enter first number: ");
    scanf("%lf", &x);

    printf("Enter second number: ");
    scanf("%lf", &y);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            printf("Result: %lf
", x + y);
            break;
        case '-':
            printf("Result: %lf
", x - y);
            break;
        case '*':
            printf("Result: %lf
", x * y);
            break;
        case '/':
            if (y != 0) {
                printf("Result: %lf
", x / y);
            } else {
                printf("Cannot divide by zero
");
            }
            break;
        default:
            printf("Invalid operator
");
            break;
    }

    return 0;
}