#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/prctl.h>

int main(int argc, char *argv[]) {
    // Perform privileged operation
    setuid(0);
    std::system(("passwd " + std::string(argv[1])).c_str());

    // Drop privileges
    setuid(getuid());

    // Verify privileges dropped
    std::system("whoami");

    return 0;
}