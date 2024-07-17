#include <iostream>
#include <cctype>
#include <cstring>

bool isValidPassword(const std::string &password) {
    if (password.length() < 8) return false;
    bool hasUpperCase = false, hasLowerCase = false, hasDigit = false;

    for (char c : password) {
        if (isupper(c)) hasUpperCase = true;
        if (islower(c)) hasLowerCase = true;
        if (isdigit(c)) hasDigit = true;
    }

    return hasUpperCase && hasLowerCase && hasDigit;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "No password provided" << std::endl;
        return 1;
    }
    if (isValidPassword(argv[1])) {
        std::cout << "Password is strong" << std::endl;
    } else {
        std::cout << "Password is weak" << std::endl;
    }
    return 0;
}