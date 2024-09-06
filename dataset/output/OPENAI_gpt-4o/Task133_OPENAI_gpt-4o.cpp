// CPP
#include <iostream>
#include <string>

void resetPassword(const std::string& username, const std::string& newPassword) {
    std::cout << "Password for " << username << " has been reset to " << newPassword << std::endl;
}

int main() {
    std::string username, newPassword;
    
    std::cout << "Enter your username: ";
    std::cin >> username;

    std::cout << "Enter your new password: ";
    std::cin >> newPassword;

    resetPassword(username, newPassword);

    return 0;
}