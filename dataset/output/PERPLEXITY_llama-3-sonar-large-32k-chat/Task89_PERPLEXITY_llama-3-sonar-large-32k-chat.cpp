#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("password.txt");
    std::string storedPassword;
    std::getline(file, storedPassword);
    file.close();
    std::string userPassword;
    std::cout << "Enter your password: ";
    std::getline(std::cin, userPassword);
    if (storedPassword.length() != userPassword.length()) {
        std::cout << "Password does not match" << std::endl;
    } else {
        bool match = true;
        for (int i = 0; i < storedPassword.length(); i++) {
            if (storedPassword[i] != userPassword[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            std::cout << "Password matches" << std::endl;
        } else {
            std::cout << "Password does not match" << std::endl;
        }
    }
    return 0;
}