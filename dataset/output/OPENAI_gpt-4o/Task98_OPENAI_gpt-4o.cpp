#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string userInput;
    std::cout << "Enter a number: ";
    std::getline(std::cin, userInput);
    int result;
    std::istringstream iss(userInput);
    if (iss >> result) {
        std::cout << "Converted Integer: " << result << std::endl;
    } else {
        std::cout << "Error: Not a valid integer" << std::endl;
    }
    return 0;
}