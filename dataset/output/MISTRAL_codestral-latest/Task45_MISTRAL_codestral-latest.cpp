#include <iostream>

int main() {
    double number;
    std::cout << "Enter a number: ";
    if (std::cin >> number) {
        double result = number * 2;
        std::cout << "The result is: " << result << std::endl;
    } else {
        std::cout << "Invalid input. Please enter a number." << std::endl;
    }
    return 0;
}