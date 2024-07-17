
#include <iostream>
#include <string>

bool checkPasswordStrength(const std::string& password) {
    if (password.length() < 8) {
        return false;
    }

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;

    for (char c : password) {
        if (std::isupper(c)) {
            hasUppercase = true;
        } else if (std::islower(c)) {
            hasLowercase = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        }
    }

    return hasUppercase && hasLowercase && hasDigit;
}

int main() {
    std::string password;
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);

    bool isStrong = checkPasswordStrength(password);

    if (isStrong) {
        std::cout << "Strong password!" << std::endl;
    } else {
        std::cout << "Weak password. Please try again." << std::endl;
    }

    return 0;
}
