
#include <iostream>
#include <stdexcept>
#include <limits>

double divide_numbers(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Cannot divide by zero.");
    }
    return a / b;
}

int main() {
    try {
        double num1, num2;
        
        std::cout << "Enter first number: ";
        if (!(std::cin >> num1)) {
            throw std::runtime_error("Invalid input for first number.");
        }

        std::cout << "Enter second number: ";
        if (!(std::cin >> num2)) {
            throw std::runtime_error("Invalid input for second number.");
        }

        double result = divide_numbers(num1, num2);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    std::cout << "Program execution completed." << std::endl;
    return 0;
}
