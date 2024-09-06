
#include <iostream>
#include <string>
#include <regex>

bool validateInput(const std::string& input) {
    std::regex pattern("^[a-zA-Z0-9\\\\s]+$");
    return std::regex_match(input, pattern);
}

std::string processInput(std::string input) {
    for (char& c : input) {
        c = std::toupper(c);
    }
    return input;
}

int main() {
    std::string userInput;

    while (true) {
        std::cout << "Enter some text (alphanumeric characters and spaces only): ";
        std::getline(std::cin, userInput);

        if (validateInput(userInput)) {
            std::string processedInput = processInput(userInput);
            std::cout << "Processed input: " << processedInput << std::endl;
            break;
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    return 0;
}
