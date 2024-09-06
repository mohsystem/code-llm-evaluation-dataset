#include <iostream>
#include <regex>

int main() {
    std::regex pattern("^[a-zA-Z0-9_]{3,16}$");
    std::string user_input;
    std::cout << "Enter a username: ";
    std::cin >> user_input;
    if (std::regex_match(user_input, pattern)) {
        std::cout << "Valid username" << std::endl;
    } else {
        std::cout << "Invalid username" << std::endl;
    }
    return 0;
}