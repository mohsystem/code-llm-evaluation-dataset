#include <iostream>
#include <csignal>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <PID>" << std::endl;
        return 1;
    }
    int pid = std::atoi(argv[1]);
    if (kill(pid, SIGKILL) == 0) {
        std::cout << "Process " << pid << " terminated." << std::endl;
    } else {
        std::perror("Error");
    }
    return 0;
}