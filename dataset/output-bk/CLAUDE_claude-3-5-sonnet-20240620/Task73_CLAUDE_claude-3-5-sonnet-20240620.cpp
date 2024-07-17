
#include <iostream>
#include <string>
#include <regex>

bool isValidPassword(const std::string& password) {
    if (password.length() < 12) return false;
    if (!std::regex_search(password, std::regex("[A-Z]"))) return false;
    if (!std::regex_search(password, std::regex("[a-z]"))) return false;
    if (!std::regex_search(password, std::regex("[0-9]"))) return false;
    if (!std::regex_search(password, std::regex("[!@#$%^&*()_+\\\\-=\\\\[\\\\]{};\':\\"\\\\\\\\|,.<>\\\\/?]"))) return false;
    return true;
}

int main() {
    std::string password;
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    if (isValidPassword(password)) {
        std::cout << "Password is valid." << std::endl;
    } else {
        std::cout << "Password is invalid." << std::endl;
    }

    return 0;
}
