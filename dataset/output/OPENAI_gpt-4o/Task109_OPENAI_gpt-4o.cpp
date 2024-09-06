#include <iostream>
#include <regex>

int main() {
    std::string user_input;
    std::cout << "Enter something: ";
    std::getline(std::cin, user_input);

    std::regex pattern("^[a-zA-Z0-9_]+$");
    
    if (std::regex_match(user_input, pattern)) {
        std::cout << "Valid input" << std::endl;
    } else {
        std::cout << "Invalid input" << std::endl;
    }
    
    return 0;
}