#include <iostream>
#include <regex>

bool checkPasswordStrength(const std::string& password) {
    if (password.length() < 8) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[a-z]"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[A-Z]"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[0-9]"))) {
        return false;
    }
    return true;
}

int main() {
    std::string password;
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);
    if (checkPasswordStrength(password)) {
        std::cout << "Password is strong" << std::endl;
    } else {
        std::cout << "Password is weak" << std::endl;
    }
    return 0;
}