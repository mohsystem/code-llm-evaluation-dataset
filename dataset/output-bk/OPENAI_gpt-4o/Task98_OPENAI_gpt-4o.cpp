#include <iostream>
#include <string>
int main() {
    std::string input;
    int number;
    std::cout << "Enter a number: ";
    std::getline(std::cin, input);
    try {
        number = std::stoi(input);
        std::cout << "You entered: " << number << std::endl;
    } catch (std::invalid_argument const &e) {
        std::cout << "Invalid input. Not an integer." << std::endl;
    }
    return 0;
}