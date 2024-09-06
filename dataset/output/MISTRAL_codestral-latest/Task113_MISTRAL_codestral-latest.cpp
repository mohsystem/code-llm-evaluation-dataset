// CPP
#include <iostream>
#include <string>

int main() {
    std::string concatenatedString = "";
    std::string userInput;

    while (true) {
        std::cout << "Enter a string (or press enter to finish): ";
        std::getline(std::cin, userInput);
        if (userInput.empty()) {
            break;
        }
        concatenatedString += userInput;
    }

    std::cout << "Concatenated string: " << concatenatedString << std::endl;

    return 0;
}