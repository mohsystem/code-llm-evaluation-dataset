#include <iostream>

int main() {
    double num;

    std::cout << "Enter a number: ";

    if (std::cin >> num) {
        std::cout << "The square of the number is: " << num * num << std::endl;
    } else {
        std::cout << "Invalid input. Please enter a number." << std::endl;
    }

    return 0;
}