#include <iostream>

int main() {
    double num1, num2;
    char operator;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> operator;

    double result;

    switch (operator) {
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
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero" << std::endl;
                return 0;
            }
            break;
        default:
            std::cout << "Error: Invalid operator" << std::endl;
            return 0;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}