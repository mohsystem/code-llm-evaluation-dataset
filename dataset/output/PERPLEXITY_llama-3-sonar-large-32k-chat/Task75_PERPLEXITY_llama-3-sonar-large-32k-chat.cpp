#include <iostream>
#include <cstdlib>
#include <csignal>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <PID>" << std::endl;
        return 1;
    }
    pid_t pid = std::atoi(argv[1]);
    if (std::kill(pid, SIGTERM) == -1) {
        std::perror("kill");
        return 1;
    }
    return 0;
}