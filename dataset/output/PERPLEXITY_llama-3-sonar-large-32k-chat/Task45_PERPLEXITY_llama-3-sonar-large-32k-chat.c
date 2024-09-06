#include <stdio.h>

int main() {
    double num1, num2;
    char operation;
    
    printf("Enter first number: ");
    while (scanf("%lf", &num1) != 1) {
        printf("Error: Invalid input!\n");
        printf("Enter first number: ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    printf("Enter second number: ");
    while (scanf("%lf", &num2) != 1) {
        printf("Error: Invalid input!\n");
        printf("Enter second number: ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    printf("Enter operation (+, -, *, /): ");
    while (scanf(" %c", &operation) != 1) {
        printf("Error: Invalid input!\n");
        printf("Enter operation (+, -, *, /): ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    if (operation == '+') {
        printf("Result: %f\n", num1 + num2);
    } else if (operation == '-') {
        printf("Result: %f\n", num1 - num2);
    } else if (operation == '*') {
        printf("Result: %f\n", num1 * num2);
    } else if (operation == '/') {
        if (num2 != 0) {
            printf("Result: %f\n", num1 / num2);
        } else {
            printf("Error: Division by zero!\n");
        }
    } else {
        printf("Error: Invalid operation!\n");
    }
    
    return 0;
}