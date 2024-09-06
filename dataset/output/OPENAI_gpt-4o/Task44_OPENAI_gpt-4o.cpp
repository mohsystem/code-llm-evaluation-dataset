#include <iostream>
#include <limits>

int main() {
    std::cout << "Enter a number: ";
    int number;
    while (!(std::cin >> number)) {
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "You entered: " << number << std::endl;

    int squared = number * number;
    std::cout << "Square of the number: " << squared << std::endl;

    return 0;
}