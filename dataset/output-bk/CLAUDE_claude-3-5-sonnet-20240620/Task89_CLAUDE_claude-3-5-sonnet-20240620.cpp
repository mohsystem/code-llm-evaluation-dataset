
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string storedPassword, enteredPassword;
    bool match = true;

    std::ifstream file("password.txt");
    if (!file.is_open()) {
        std::cout << "Password file not found." << std::endl;
        return 1;
    }

    std::getline(file, storedPassword);
    file.close();

    std::cout << "Enter password: ";
    std::getline(std::cin, enteredPassword);

    if (storedPassword.length() != enteredPassword.length()) {
        match = false;
    } else {
        for (size_t i = 0; i < storedPassword.length(); i++) {
            if (storedPassword[i] != enteredPassword[i]) {
                match = false;
                break;
            }
        }
    }

    if (match) {
        std::cout << "Password correct!" << std::endl;
    } else {
        std::cout << "Password incorrect!" << std::endl;
    }

    return 0;
}
