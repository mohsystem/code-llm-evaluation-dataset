// C++
#include <iostream>
#include <cstdlib>
#include <csignal>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <PID>
";
        return 1;
    }

    int pid = std::atoi(argv[1]);

    if (pid <= 0) {
        std::cout << "Invalid PID.
";
        return 1;
    }

    if (pid == getpid()) {
        std::cout << "Cannot terminate the current process.
";
        return 1;
    }

    if (kill(pid, SIGTERM) == -1) {
        perror("Error terminating process");
        return 1;
    }

    std::cout << "Process " << pid << " terminated.
";
    return 0;
}