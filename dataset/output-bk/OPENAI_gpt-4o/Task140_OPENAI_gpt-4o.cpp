#include <iostream>

int main() {
    double x, y;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> x;

    std::cout << "Enter second number: ";
    std::cin >> y;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    switch (op) {
        case '+':
            std::cout << "Result: " << x + y << std::endl;
            break;
        case '-':
            std::cout << "Result: " << x - y << std::endl;
            break;
        case '*':
            std::cout << "Result: " << x * y << std::endl;
            break;
        case '/':
            if (y != 0) {
                std::cout << "Result: " << x / y << std::endl;
            } else {
                std::cout << "Cannot divide by zero" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operator" << std::endl;
            break;
    }

    return 0;
}