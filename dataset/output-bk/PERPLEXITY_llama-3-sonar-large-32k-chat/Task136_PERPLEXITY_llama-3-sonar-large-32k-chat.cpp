// C++ code
#include <iostream>
#include <string>

int main() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    if (username == "admin" && password == "password") {
        std::cout << "Login successful!" << std::endl;
    } else {
        std::cout << "Invalid username or password" << std::endl;
    }
    return 0;
}