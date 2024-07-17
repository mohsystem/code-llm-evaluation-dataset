#include <iostream>
#include <cstdlib>

int main() {
    std::string input;
    long number;

    std::cout << "Enter a number: ";
    std::getline(std::cin, input);

    try {
        number = std::stol(input);
        std::cout << "You entered: " << number << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Invalid input. The number is out of range." << std::endl;
    }

    return 0;
}