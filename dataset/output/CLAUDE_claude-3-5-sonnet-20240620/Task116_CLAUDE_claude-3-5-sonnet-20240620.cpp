
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() {
    std::string username;
    std::string password;
    
    std::cout << "Enter username to change password: ";
    std::cin >> username;
    
    std::cout << "Enter new password: ";
    std::cin >> password;

    // Perform privileged operation
    std::string command = "sudo passwd " + username;
    int result = system(command.c_str());
    if (result == 0) {
        std::cout << "Password changed successfully" << std::endl;
    } else {
        std::cerr << "Failed to change password" << std::endl;
        return 1;
    }

    // Drop privileges
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (pw == nullptr) {
        std::cerr << "Failed to get user information" << std::endl;
        return 1;
    }

    if (setuid(pw->pw_uid) != 0) {
        std::cerr << "Failed to drop privileges" << std::endl;
        return 1;
    }

    std::cout << "Privileges dropped" << std::endl;
    return 0;
}
