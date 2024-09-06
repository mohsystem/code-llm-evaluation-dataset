#include <iostream>
#include <cctype>

bool checkPassword(const std::string& password) {
    if (password.length() < 8) {
        return false;
    }
    bool hasDigit = false;
    bool hasUpper = false;
    bool hasLower = false;
    for (char c : password) {
        if (std::isdigit(c)) {
            hasDigit = true;
        }
        if (std::isupper(c)) {
            hasUpper = true;
        }
        if (std::islower(c)) {
            hasLower = true;
        }
    }
    return hasDigit && hasUpper && hasLower;
}

int main() {
    std::string password;
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    if (checkPassword(password)) {
        std::cout << "Password is valid" << std::endl;
    } else {
        std::cout << "Password is not valid" << std::endl;
    }
    return 0;
}