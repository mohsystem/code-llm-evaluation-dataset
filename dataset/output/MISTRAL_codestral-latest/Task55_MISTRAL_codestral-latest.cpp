#include <iostream>
#include <regex>

bool validateEmail(const std::string& email) {
    const std::regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return std::regex_match(email, pattern);
}

int main() {
    std::string email;
    std::cout << "Enter your email: ";
    std::cin >> email;
    if (validateEmail(email)) {
        std::cout << "Email is valid" << std::endl;
    } else {
        std::cout << "Email is invalid" << std::endl;
    }
    return 0;
}