#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string email;
    std::cout << "Enter your email:";
    std::getline(std::cin, email);
    std::regex regex("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
    if (std::regex_match(email, regex)) {
        std::cout << "Email is valid" << std::endl;
    } else {
        std::cout << "Email is not valid" << std::endl;
    }
    return 0;
}