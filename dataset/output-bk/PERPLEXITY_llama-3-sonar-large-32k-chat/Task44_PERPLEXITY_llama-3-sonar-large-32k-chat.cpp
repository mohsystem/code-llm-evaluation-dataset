#include <iostream>
#include <limits>

int main() {
    int num1, num2;

    while (true) {
        std::cout << "Enter first number: ";
        if (std::cin >> num1) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid number.
";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '
');
        }
    }

    while (true) {
        std::cout << "Enter second number: ";
        if (std::cin >> num2) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid number.
";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '
');
        }
    }

    std::cout << "Sum: " << num1 + num2 << std::endl;
    std::cout << "Difference: " << num1 - num2 << std::endl;
    std::cout << "Product: " << num1 * num2 << std::endl;
    if (num2 != 0) {
        std::cout << "Quotient: " << num1 / num2 << std::endl;
    } else {
        std::cout << "Cannot divide by zero." << std::endl;
    }

    return 0;
}