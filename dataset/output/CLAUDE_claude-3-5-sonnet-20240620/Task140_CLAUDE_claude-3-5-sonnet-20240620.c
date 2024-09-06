
#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;
    
    printf("Enter first number: ");
    scanf("%lf", &num1);
    
    printf("Enter second number: ");
    scanf("%lf", &num2);
    
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);
    
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero\\n");
                return 1;
            }
            break;
        default:
            printf("Error: Invalid operator\\n");
            return 1;
    }
    
    printf("Result: %f\\n", result);
    
    return 0;
}
