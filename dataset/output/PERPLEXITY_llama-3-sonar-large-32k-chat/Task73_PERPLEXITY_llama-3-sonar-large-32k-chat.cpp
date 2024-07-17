#include <iostream>
#include <string>

int main() {
    std::string password;
    std::cout << "Enter password:";
    std::cin >> password;
    if (password == "admin123") {
        std::cout << "Password is valid" << std::endl;
    } else {
        std::cout << "Password is not valid" << std::endl;
    }
    return 0;
}