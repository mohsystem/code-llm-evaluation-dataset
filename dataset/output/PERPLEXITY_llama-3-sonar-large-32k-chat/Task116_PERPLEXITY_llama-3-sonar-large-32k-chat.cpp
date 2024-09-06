#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void drop_privileges(uid_t uid, gid_t gid) {
    setgid(gid);
    setuid(uid);
}

int main() {
    std::string username;
    std::string password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter new password: ";
    std::cin >> password;
    std::string command = "echo '" + password + "' | sudo -S passwd " + username;
    system(command.c_str());
    struct passwd *pw = getpwnam("nobody");  // replace with desired username
    drop_privileges(pw->pw_uid, pw->pw_gid);
    return 0;
}