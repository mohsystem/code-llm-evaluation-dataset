#include <iostream>
#include <regex>

int main() {
    std::string email;
    std::regex emailRegex("^[A-Za-z0-9+_.-]+@(.+)$");

    std::cout << "Enter email address: ";
    std::getline(std::cin, email);

    if (std::regex_match(email, emailRegex)) {
        std::cout << "Valid email address" << std::endl;
    } else {
        std::cout << "Invalid email address" << std::endl;
    }

    return 0;
}