#include <iostream>
#include <string>

bool authenticate(const std::string& username, const std::string& password) {
    std::string storedUsername = "user";
    std::string storedPassword = "pass";
    return username == storedUsername && password == storedPassword;
}

int main() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    if (authenticate(username, password)) {
        std::cout << "Access granted" << std::endl;
    } else {
        std::cout << "Access denied" << std::endl;
    }

    return 0;
}