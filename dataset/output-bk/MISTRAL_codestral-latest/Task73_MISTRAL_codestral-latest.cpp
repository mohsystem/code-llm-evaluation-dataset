// C++
#include <iostream>
#include <string>

int main() {
    std::string password;
    std::cout << "Enter admin password: ";
    std::cin >> password;

    if (password == "admin123") {
        std::cout << "Password is valid.
";
    } else {
        std::cout << "Password is invalid.
";
    }

    return 0;
}