#include <iostream>
#include <string>

int main() {
    std::string username, oldPassword, newPassword, confirmPassword;

    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    std::cout << "Enter your old password: ";
    std::getline(std::cin, oldPassword);
    std::cout << "Enter your new password: ";
    std::getline(std::cin, newPassword);
    std::cout << "Confirm your new password: ";
    std::getline(std::cin, confirmPassword);

    if (newPassword == confirmPassword) {
        std::cout << "Password reset successfully!" << std::endl;
    } else {
        std::cout << "New password and confirm password do not match. Please try again." << std::endl;
    }

    return 0;
}