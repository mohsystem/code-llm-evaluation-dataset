
#include <iostream>
#include <cstdlib>
#include <csignal>
#include <cerrno>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <PID>" << std::endl;
        return 1;
    }

    try {
        int pid = std::stoi(argv[1]);
        if (kill(pid, SIGKILL) == 0) {
            std::cout << "Process with PID " << pid << " has been terminated." << std::endl;
        } else {
            std::cerr << "Failed to terminate process with PID " << pid << ": " << strerror(errno) << std::endl;
        }
    } catch (const std::invalid_argument&) {
        std::cerr << "Invalid PID. Please provide a valid integer." << std::endl;
    } catch (const std::out_of_range&) {
        std::cerr << "PID is out of range." << std::endl;
    }

    return 0;
}
