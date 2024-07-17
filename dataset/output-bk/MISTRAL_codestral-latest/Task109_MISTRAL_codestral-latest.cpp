#include <iostream>
#include <regex>

int main() {
    std::string input;
    std::cout << "Enter input: ";
    std::getline(std::cin, input);

    // Regex pattern to validate input
    std::regex regex("^[a-zA-Z0-9]*$");
    if(std::regex_match(input, regex)) {
        std::cout << "Valid input
";
    } else {
        std::cout << "Invalid input
";
    }

    return 0;
}