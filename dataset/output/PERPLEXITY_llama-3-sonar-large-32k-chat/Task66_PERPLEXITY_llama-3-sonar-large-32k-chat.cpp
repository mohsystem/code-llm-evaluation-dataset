#include <iostream>
#include <string>
#include <stdexcept>

bool validateCommand(const std::string& command) {
    // Add your validation logic here
    return true;
}

std::string executeCommand(const std::string& command) {
    try {
        std::string cmd = "bash -c \"" + command + "\"";
        FILE* pipe = popen(cmd.c_str(), "r");
        if (!pipe) {
            return "Error: unable to open pipe";
        }
        char buffer[128];
        std::string result;
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL) {
                result += buffer;
            }
        }
        pclose(pipe);
        return result;
    } catch (const std::exception& e) {
        return "Error: " + std::string(e.what());
    }
}

int main() {
    std::cout << "Enter a bash shell command: ";
    std::string command;
    std::getline(std::cin, command);
    if (validateCommand(command)) {
        std::string result = executeCommand(command);
        std::cout << result;
    } else {
        std::cout << "Invalid command format or content";
    }
    return 0;
}