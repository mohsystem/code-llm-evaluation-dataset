#include <iostream>
#include <signal.h>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./kill_process <PID>" << std::endl;
        return 1;
    }

    int pid = std::atoi(argv[1]);
    if (kill(pid, SIGKILL) == -1) {
        std::cerr << "Failed to kill process with PID " << pid << std::endl;
        return 1;
    }

    return 0;
}