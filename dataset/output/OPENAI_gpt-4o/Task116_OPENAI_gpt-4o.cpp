#include <iostream>
#include <unistd.h>
#include <cstdlib>

int main() {
    if (geteuid() != 0) {
        std::cerr << "This script must be run as root!" << std::endl;
        return 1;
    }

    std::string username;
    std::cout << "Enter username to change password: ";
    std::cin >> username;

    std::string command = "echo \"" + username + ":newpassword\" | chpasswd";
    system(command.c_str());

    // Drop privileges
    if (setuid(geteuid()) != 0) {
        std::cerr << "Failed to drop privileges" << std::endl;
        return 1;
    }
    std::cout << "Privileges have been dropped." << std::endl;
    return 0;
}