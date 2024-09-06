
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <cstring>

void drop_privileges(const char* username = "nobody") {
    struct passwd* pw = getpwnam(username);
    if (pw == nullptr) {
        std::cerr << "Failed to get user info for " << username << std::endl;
        exit(1);
    }

    if (setgid(pw->pw_gid) != 0) {
        std::cerr << "Failed to set GID: " << strerror(errno) << std::endl;
        exit(1);
    }

    if (setuid(pw->pw_uid) != 0) {
        std::cerr << "Failed to set UID: " << strerror(errno) << std::endl;
        exit(1);
    }

    std::cout << "Privileges dropped to " << username << std::endl;
}

void change_password(const std::string& username, const std::string& password) {
    std::string command = "echo '" + password + "\\\\n" + password + "' | passwd " + username;
    int result = system(command.c_str());
    if (result == 0) {
        std::cout << "Password changed successfully for " << username << std::endl;
    } else {
        std::cerr << "Failed to change password for " << username << std::endl;
    }
}

int main() {
    if (geteuid() != 0) {
        std::cerr << "This program must be run as root." << std::endl;
        return 1;
    }

    std::string username, password;
    std::cout << "Enter username to change password: ";
    std::cin >> username;
    std::cout << "Enter new password: ";
    std::cin >> password;

    change_password(username, password);

    std::cout << "Dropping privileges..." << std::endl;
    drop_privileges();

    std::cout << "Program continues with reduced privileges..." << std::endl;

    return 0;
}
