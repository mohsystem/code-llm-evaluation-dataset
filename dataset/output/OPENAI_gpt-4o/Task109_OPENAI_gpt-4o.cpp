#include <iostream>
#include <regex>

int main() {
    std::string input;
    std::regex pattern("^[a-zA-Z0-9]*$");

    std::cout << "Enter a string in C++:" << std::endl;
    std::getline(std::cin, input);
    if (std::regex_match(input, pattern)) {
        std::cout << "Valid C++ Input" << std::endl;
    } else {
        std::cout << "Invalid C++ Input" << std::endl;
    }

    return 0;
}