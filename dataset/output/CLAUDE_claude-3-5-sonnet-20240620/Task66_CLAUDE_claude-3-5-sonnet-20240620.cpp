
#include <iostream>
#include <string>
#include <regex>
#include <cstdio>
#include <array>
#include <memory>

bool validate_command(const std::string& command) {
    // Check if command is empty
    if (command.empty()) {
        return false;
    }

    // Check for semicolons, pipes, or redirections
    std::regex invalid_chars_regex("[;|><]");
    return !std::regex_search(command, invalid_chars_regex);
}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main() {
    std::string command;
    std::cout << "Enter a bash command: ";
    std::getline(std::cin, command);

    if (validate_command(command)) {
        try {
            std::string output = exec(command.c_str());
            std::cout << output;
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    } else {
        std::cout << "Invalid command format or content." << std::endl;
    }

    return 0;
}
