
#include <iostream>
#include <cstdlib>
#include <csignal>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <PID>" << std::endl;
        return 1;
    }

    int pid = std::atoi(argv[1]);
    if (pid <= 0) {
        std::cout << "Invalid PID. Please provide a valid positive integer." << std::endl;
        return 1;
    }

    if (kill(pid, SIGTERM) == 0) {
        std::cout << "Process with PID " << pid << " terminated successfully." << std::endl;
    } else {
        std::perror("Failed to terminate process");
        return 1;
    }

    return 0;
}
