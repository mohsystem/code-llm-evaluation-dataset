#include <stdio.h>

int main() {
    double num1, num2;
    char op;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch (op) {
        case '+':
            printf("%lf
", num1 + num2);
            break;
        case '-':
            printf("%lf
", num1 - num2);
            break;
        case '*':
            printf("%lf
", num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Division by zero not allowed
");
            } else {
                printf("%lf
", num1 / num2);
            }
            break;
        default:
            printf("Invalid input
");
    }

    return 0;
}