
#include <iostream>
#include <stdexcept>
#include <limits>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        int num, divisor, result, index;
        int array[5] = {0};

        std::cout << "Enter a number: ";
        if (!(std::cin >> num)) {
            throw std::runtime_error("Invalid input. Please enter a valid integer.");
        }

        std::cout << "Enter another number: ";
        if (!(std::cin >> divisor)) {
            throw std::runtime_error("Invalid input. Please enter a valid integer.");
        }

        result = divide(num, divisor);
        std::cout << "Result of division: " << result << std::endl;

        std::cout << "Enter an index to access the array: ";
        if (!(std::cin >> index)) {
            throw std::runtime_error("Invalid input. Please enter a valid integer.");
        }

        if (index < 0 || index >= 5) {
            throw std::out_of_range("Array index out of bounds");
        }

        std::cout << "Value at index " << index << ": " << array[index] << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
