#include <iostream>
#include <regex>

bool isValidEmail(const std::string& email);

int main() {
    std::string email;
    std::cout << "Enter an email address:" << std::endl;
    std::cin >> email;
    if (isValidEmail(email)) {
        std::cout << "Valid email address." << std::endl;
    } else {
        std::cout << "Invalid email address." << std::endl;
    }
    return 0;
}

bool isValidEmail(const std::string& email) {
    const std::regex emailRegex("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$");
    return std::regex_match(email, emailRegex);
}