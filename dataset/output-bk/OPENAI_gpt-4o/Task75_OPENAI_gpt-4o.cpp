#include <iostream>
#include <cstdlib>
#include <csignal>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <pid>" << std::endl;
        return 1;
    }
    
    pid_t pid = (pid_t)std::atoi(argv[1]);
    if (kill(pid, SIGKILL) == 0) {
        std::cout << "Process " << pid << " terminated." << std::endl;
    } else {
        perror("Failed to terminate process");
        return 1;
    }
    
    return 0;
}