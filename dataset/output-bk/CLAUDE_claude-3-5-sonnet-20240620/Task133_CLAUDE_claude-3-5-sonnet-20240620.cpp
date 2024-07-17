
#include <iostream>
#include <string>
#include <random>
#include <algorithm>

std::string generatePassword(int length = 12) {
    const std::string CHAR_SET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, CHAR_SET.size() - 1);

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += CHAR_SET[distribution(generator)];
    }
    return password;
}

std::string resetPassword(const std::string& username) {
    std::string newPassword = generatePassword();
    std::cout << "Password for " << username << " has been reset." << std::endl;
    std::cout << "New password: " << newPassword << std::endl;
    // In a real system, you would hash and save this password
    return newPassword;
}

int main() {
    std::string username;
    std::cout << "Enter username to reset password: ";
    std::getline(std::cin, username);
    resetPassword(username);
    return 0;
}
