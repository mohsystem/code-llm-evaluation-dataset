
#include <iostream>
#include <regex>
#include <string>

bool is_valid_email(const std::string& email) {
    const std::regex pattern("^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$");
    return std::regex_match(email, pattern);
}

int main() {
    std::string email;
    std::cout << "Enter an email address: ";
    std::getline(std::cin, email);

    if (is_valid_email(email)) {
        std::cout << "Valid email address" << std::endl;
    } else {
        std::cout << "Invalid email address" << std::endl;
    }

    return 0;
}
