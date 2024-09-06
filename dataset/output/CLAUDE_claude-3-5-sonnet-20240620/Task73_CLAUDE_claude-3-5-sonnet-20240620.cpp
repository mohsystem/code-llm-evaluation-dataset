
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

bool isValidAdminPassword(const std::string& password) {
    if (password.length() < 12) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[A-Z]"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[a-z]"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("\\\\d"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[!@#$%^&*(),.?\\":{}|<>]"))) {
        return false;
    }
    std::string lowercasePassword = password;
    std::transform(lowercasePassword.begin(), lowercasePassword.end(), lowercasePassword.begin(), ::tolower);
    if (lowercasePassword.find("admin") != std::string::npos) {
        return false;
    }
    return true;
}

int main() {
    std::string password;
    std::cout << "Enter the admin password: ";
    std::getline(std::cin, password);
    if (isValidAdminPassword(password)) {
        std::cout << "Password is valid" << std::endl;
    } else {
        std::cout << "Password is invalid" << std::endl;
    }
    return 0;
}
