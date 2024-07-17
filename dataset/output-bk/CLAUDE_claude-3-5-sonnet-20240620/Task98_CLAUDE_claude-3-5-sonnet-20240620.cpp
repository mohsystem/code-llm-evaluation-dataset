
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::getline(std::cin, input);
    
    try {
        int number = std::stoi(input);
        std::cout << "Converted integer: " << number << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid input. Not a valid integer." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Input out of range for integer conversion." << std::endl;
    }
    
    return 0;
}
