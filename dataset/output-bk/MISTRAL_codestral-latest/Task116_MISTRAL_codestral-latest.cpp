// C++
#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Running as root
";
    uid_t uid = getuid();
    gid_t gid = getgid();

    // Perform privileged operations here

    // Drop privileges
    setgid(gid);
    setuid(uid);
    std::cout << "Dropped privileges
";
    return 0;
}