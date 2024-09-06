
#include <iostream>
#include <regex>
#include <string>

bool validateEmail(const std::string& email) {
    const std::regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\\\.[a-zA-Z]{2,}$");
    return std::regex_match(email, pattern);
}

int main() {
    std::string email;
    std::cout << "Enter an email address: ";
    std::getline(std::cin, email);

    if (validateEmail(email)) {
        std::cout << "Valid email address" << std::endl;
    } else {
        std::cout << "Invalid email address" << std::endl;
    }

    return 0;
}
