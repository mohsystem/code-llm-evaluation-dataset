#include <iostream>
#include <cctype>
#include <string>

bool isValidPassword(const std::string& password) {
    if (password.length() < 8) return false;
    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char c : password) {
        if (std::isupper(c)) hasUpper = true;
        if (std::islower(c)) hasLower = true;
        if (std::isdigit(c)) hasDigit = true;
    }
    return hasUpper && hasLower && hasDigit;
}

int main() {
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;
    if (isValidPassword(password)) {
        std::cout << "Strong password
";
    } else {
        std::cout << "Weak password
";
    }
    return 0;
}