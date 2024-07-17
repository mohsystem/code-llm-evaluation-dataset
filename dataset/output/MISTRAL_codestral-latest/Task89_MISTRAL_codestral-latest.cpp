#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputPassword;
    std::string storedPassword;

    std::cout << "Enter password: ";
    std::getline(std::cin, inputPassword);

    std::ifstream file("password.txt");
    if (!file.is_open()) {
        std::cout << "An error occurred while reading the file.
";
        return 1;
    }

    std::getline(file, storedPassword);

    if (inputPassword == storedPassword) {
        std::cout << "Password is correct.
";
    } else {
        std::cout << "Password is incorrect.
";
    }

    file.close();
    return 0;
}