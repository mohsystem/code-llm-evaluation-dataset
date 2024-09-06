#include <stdio.h>

int main() {
    double num1, num2;
    char op;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &op); // Note the space before %c to consume the newline character
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch (op) {
        case '+':
            printf("%lf\n", num1 + num2);
            break;
        case '-':
            printf("%lf\n", num1 - num2);
            break;
        case '*':
            printf("%lf\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Division by zero error!\n");
            } else {
                printf("%lf\n", num1 / num2);
            }
            break;
        default:
            printf("Invalid operator!\n");
    }

    return 0;
}