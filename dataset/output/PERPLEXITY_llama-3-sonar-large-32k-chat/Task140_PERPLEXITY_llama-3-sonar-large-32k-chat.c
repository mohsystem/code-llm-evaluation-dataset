#include<stdio.h>

int main() {
    double num1, num2;
    char operator_;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator_);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    if (operator_ == '+') {
        printf("Result: %f\n", num1 + num2);
    } else if (operator_ == '-') {
        printf("Result: %f\n", num1 - num2);
    } else if (operator_ == '*') {
        printf("Result: %f\n", num1 * num2);
    } else if (operator_ == '/') {
        if (num2 != 0) {
            printf("Result: %f\n", num1 / num2);
        } else {
            printf("Error Division by zero is not allowed.\n");
        }
    } else {
        printf("Invalid operator. Please enter either +, -, * or /.\n");
    }

    return 0;
}