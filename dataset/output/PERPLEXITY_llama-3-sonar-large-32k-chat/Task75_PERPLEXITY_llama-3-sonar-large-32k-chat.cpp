#include <iostream>
#include <cstdlib>
#include <csignal>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: terminate_process <PID>" << std::endl;
        return 1;
    }

    int pid = std::atoi(argv[1]);
    if (kill(pid, SIGKILL) == -1) {
        std::cout << "Error: unable to terminate process" << std::endl;
        return 1;
    }

    return 0;
}