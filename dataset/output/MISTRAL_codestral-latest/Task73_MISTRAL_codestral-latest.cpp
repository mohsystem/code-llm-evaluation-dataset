#include <iostream>
#include <regex>

bool isValidPassword(const std::string& password) {
    // Admin password requirements:
    // - At least 8 characters long
    // - Contains at least one uppercase letter
    // - Contains at least one lowercase letter
    // - Contains at least one digit
    // - Contains at least one special character

    if (password.length() < 8) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[A-Z]"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[a-z]"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("\\d"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[!@#$%^&*()-_=+\\[\\]{}|;:,.<>\\?]"))) {
        return false;
    }
    return true;
}

int main() {
    std::string password;
    std::cout << "Enter admin password: ";
    std::getline(std::cin, password);

    if (isValidPassword(password)) {
        std::cout << "Password is valid.\n";
    } else {
        std::cout << "Password is invalid.\n";
    }

    return 0;
}