
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string input;

    // Email validation
    std::regex email_pattern("^[\\\\w\\\\.-]+@[\\\\w\\\\.-]+\\\\.\\\\w+$");
    std::cout << "Enter your email: ";
    std::getline(std::cin, input);
    if (std::regex_match(input, email_pattern)) {
        std::cout << "Valid email" << std::endl;
    } else {
        std::cout << "Invalid email" << std::endl;
    }

    // Phone number validation (US format)
    std::regex phone_pattern("^\\\\(?([0-9]{3})\\\\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$");
    std::cout << "Enter your phone number: ";
    std::getline(std::cin, input);
    if (std::regex_match(input, phone_pattern)) {
        std::cout << "Valid phone number" << std::endl;
    } else {
        std::cout << "Invalid phone number" << std::endl;
    }

    // Password validation (at least 8 characters, 1 uppercase, 1 lowercase, 1 digit)
    std::regex password_pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\\\d)[a-zA-Z\\\\d]{8,}$");
    std::cout << "Enter your password: ";
    std::getline(std::cin, input);
    if (std::regex_match(input, password_pattern)) {
        std::cout << "Valid password" << std::endl;
    } else {
        std::cout << "Invalid password" << std::endl;
    }

    return 0;
}
