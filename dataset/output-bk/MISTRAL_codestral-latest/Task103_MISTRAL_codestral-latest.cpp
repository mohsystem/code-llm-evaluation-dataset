#include <iostream>
#include <cctype>
#include <string>

bool isValidPassword(const std::string& password) {
    if (password.length() < 8) {
        return false;
    }

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;

    for (char c : password) {
        if (std::isupper(c)) {
            hasUpperCase = true;
        } else if (std::islower(c)) {
            hasLowerCase = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        }
    }

    return hasUpperCase && hasLowerCase && hasDigit;
}

int main() {
    std::string password;
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);

    if (isValidPassword(password)) {
        std::cout << "Password is strong." << std::endl;
    } else {
        std::cout << "Password is weak. It should be at least 8 characters long, contain both uppercase and lowercase letters, and contain at least one digit." << std::endl;
    }

    return 0;
}