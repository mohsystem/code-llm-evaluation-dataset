#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string password;
    std::cout << "Enter your password: ";
    std::cin >> password;

    bool hasLower = false, hasUpper = false, hasDigit = false;

    if (password.length() >= 8) {
        for (char c : password) {
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;
            if (isdigit(c)) hasDigit = true;
        }
    }

    if (hasLower && hasUpper && hasDigit && password.length() >= 8) {
        std::cout << "Password is strong." << std::endl;
    } else {
        std::cout << "Password is weak." << std::endl;
    }

    return 0;
}