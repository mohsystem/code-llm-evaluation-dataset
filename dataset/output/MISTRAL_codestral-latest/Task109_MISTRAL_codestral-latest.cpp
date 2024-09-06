#include <iostream>
#include <regex>

bool validateInput(const std::string& userInput) {
    std::regex pattern("^[a-zA-Z0-9_]+$");
    return std::regex_match(userInput, pattern);
}

int main() {
    std::string userInput;
    std::cout << "Enter your input: ";
    std::getline(std::cin, userInput);
    if (validateInput(userInput)) {
        std::cout << "Input is valid" << std::endl;
    } else {
        std::cout << "Input is invalid" << std::endl;
    }
    return 0;
}