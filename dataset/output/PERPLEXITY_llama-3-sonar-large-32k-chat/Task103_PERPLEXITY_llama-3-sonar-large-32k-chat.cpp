#include <iostream>
#include <cctype>

bool passwordStrength(const std::string& password) {
    if (password.length() < 8) {
        return false;
    }
    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char c : password) {
        if (std::isupper(c)) {
            hasUpper = true;
        } else if (std::islower(c)) {
            hasLower = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        }
        if (hasUpper && hasLower && hasDigit) {
            break;
        }
    }
    return hasUpper && hasLower && hasDigit;
}

int main() {
    std::string password;
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);
    if (passwordStrength(password)) {
        std::cout << "Strong password" << std::endl;
    } else {
        std::cout << "Weak password" << std::endl;
    }
    return 0;
}