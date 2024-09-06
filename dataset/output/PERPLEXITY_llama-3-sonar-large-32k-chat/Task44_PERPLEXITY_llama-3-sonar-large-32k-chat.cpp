#include <iostream>
#include <string>
#include <cctype>

std::string getUserInput(const std::string& prompt) {
    std::string inputStr;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, inputStr);
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Invalid input. Please try again." << std::endl;
        } else {
            return inputStr;
        }
    }
}

void validateInput(const std::string& inputStr) {
    for (char c : inputStr) {
        if (!std::isalpha(c)) {
            throw std::runtime_error("Input should only contain alphabets");
        }
    }
}

int main() {
    std::string inputStr = getUserInput("Enter a string: ");
    try {
        validateInput(inputStr);
        std::cout << "Input is valid" << std::endl;
        for (char& c : inputStr) {
            c = std::toupper(c);
        }
        std::cout << "Upper case: " << inputStr << std::endl;
        for (char& c : inputStr) {
            c = std::tolower(c);
        }
        std::cout << "Lower case: " << inputStr << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}