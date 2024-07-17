#include <iostream>
#include <regex>

bool isValidEmail(const std::string& email) {
    std::regex regex("^[A-Za-z0-9+_.-]+@(.+)$");
    return std::regex_match(email, regex);
}

int main() {
    std::string email = "user@example.com";
    if (isValidEmail(email)) {
        std::cout << "Valid Email" << std::endl;
    } else {
        std::cout << "Invalid Email" << std::endl;
    }
    return 0;
}