// C++
#include <iostream>
#include <string>

int main() {
    std::string currentPassword, newPassword, confirmPassword;

    std::cout << "Enter your current password: ";
    std::getline(std::cin, currentPassword);

    std::cout << "Enter your new password: ";
    std::getline(std::cin, newPassword);

    std::cout << "Confirm your new password: ";
    std::getline(std::cin, confirmPassword);

    if (newPassword == confirmPassword) {
        std::cout << "Password reset successful." << std::endl;
    } else {
        std::cout << "Passwords do not match. Password reset failed." << std::endl;
    }

    return 0;
}