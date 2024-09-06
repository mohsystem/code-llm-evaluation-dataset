#include <stdio.h>

double calculate(double a, double b, char operator) {
    switch (operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

int main() {
    double a, b;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &a);

    printf("Enter second number: ");
    scanf("%lf", &b);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);  // note the space before %c to consume the newline

    printf("Result: %lf\n", calculate(a, b, operator));

    return 0;
}