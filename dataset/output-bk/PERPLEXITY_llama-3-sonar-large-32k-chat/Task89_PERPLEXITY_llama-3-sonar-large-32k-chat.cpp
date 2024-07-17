#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputPassword;
    std::string storedPassword;

    std::cout << "Enter password: ";
    std::cin >> inputPassword;

    std::ifstream file("password.txt");
    file >> storedPassword;
    file.close();

    bool isValid = true;
    if (inputPassword.length() != storedPassword.length()) {
        isValid = false;
    } else {
        for (int i = 0; i < inputPassword.length(); i++) {
            if (inputPassword[i] != storedPassword[i]) {
                isValid = false;
                break;
            }
        }
    }

    if (isValid) {
        std::cout << "Password is valid" << std::endl;
    } else {
        std::cout << "Password is invalid" << std::endl;
    }

    return 0;
}