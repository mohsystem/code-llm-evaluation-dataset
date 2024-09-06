#include <iostream>
#include <limits>

int main() {
    double num1, num2;
    char operation;
    
    std::cout << "Enter first number: ";
    while (!(std::cin >> num1)) {
        std::cout << "Error: Invalid input!\n";
        std::cout << "Enter first number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::cout << "Enter second number: ";
    while (!(std::cin >> num2)) {
        std::cout << "Error: Invalid input!\n";
        std::cout << "Enter second number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::cout << "Enter operation (+, -, *, /): ";
    while (!(std::cin >> operation)) {
        std::cout << "Error: Invalid input!\n";
        std::cout << "Enter operation (+, -, *, /): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    if (operation == '+') {
        std::cout << "Result: " << num1 + num2 << std::endl;
    } else if (operation == '-') {
        std::cout << "Result: " << num1 - num2 << std::endl;
    } else if (operation == '*') {
        std::cout << "Result: " << num1 * num2 << std::endl;
    } else if (operation == '/') {
        if (num2 != 0) {
            std::cout << "Result: " << num1 / num2 << std::endl;
        } else {
            std::cout << "Error: Division by zero!" << std::endl;
        }
    } else {
        std::cout << "Error: Invalid operation!" << std::endl;
    }
    
    return 0;
}