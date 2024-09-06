#include <iostream>
#include <fstream>
#include <string>

bool checkPassword(const std::string& inputPassword) {
    std::ifstream file("password.txt");
    if (!file.is_open()) return false;

    std::string storedPassword;
    std::getline(file, storedPassword);
    file.close();

    if (storedPassword.length() != inputPassword.length()) return false;

    for (size_t i = 0; i < storedPassword.length(); ++i) {
        if (storedPassword[i] != inputPassword[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string password = "correctpassword";
    std::ofstream file("password.txt");
    file << password;
    file.close();

    std::string userInput;
    std::cout << "Enter your password: ";
    std::cin >> userInput;

    if (checkPassword(userInput)) {
        std::cout << "Password is correct" << std::endl;
    } else {
        std::cout << "Password is incorrect" << std::endl;
    }

    return 0;
}