#include <iostream>
#include <cstdio>
#include <regex>

bool isValidCommand(const std::string &command) {
    std::regex validPattern("[a-zA-Z0-9\\s-_/.]+");
    return std::regex_match(command, validPattern);
}

int main() {
    std::string command;
    
    std::cout << "Enter shell command: ";
    std::getline(std::cin, command);

    if (isValidCommand(command)) {
        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) {
            std::cerr << "Failed to run command." << std::endl;
            return 1;
        }

        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            std::cout << buffer;
        }

        pclose(pipe);
    } else {
        std::cerr << "Invalid command." << std::endl;
    }

    return 0;
}