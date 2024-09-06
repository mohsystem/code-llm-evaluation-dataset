#include <iostream>
#include <cstdio>
#include <cstring>

bool validateCommand(const std::string& command) {
    // Simple validation: check if command is not empty
    return !command.empty() && command.find_first_not_of(' ') != std::string::npos;
}

int main() {
    std::string command;
    std::cout << "Enter a bash shell command: ";
    std::getline(std::cin, command);

    if (validateCommand(command)) {
        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) {
            std::cerr << "Error: Failed to execute command" << std::endl;
            return 1;
        }

        char buffer[256];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            std::cout << buffer;
        }

        pclose(pipe);
    } else {
        std::cout << "Invalid command" << std::endl;
    }

    return 0;
}