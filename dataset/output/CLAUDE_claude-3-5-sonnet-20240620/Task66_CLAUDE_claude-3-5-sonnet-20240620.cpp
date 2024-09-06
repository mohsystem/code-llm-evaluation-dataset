
#include <iostream>
#include <string>
#include <regex>
#include <cstdio>
#include <array>
#include <memory>

bool validateCommand(const std::string& cmd) {
    if (cmd.empty() || std::regex_search(cmd, std::regex("(rm|sudo|mv|cp|chmod|chown)"))) {
        return false;
    }
    return true;
}

std::string executeCommand(const std::string& cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        return "Error executing command";
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main() {
    std::string userInput;
    while (true) {
        std::cout << "Enter a bash command (or 'exit' to quit): ";
        std::getline(std::cin, userInput);
        if (userInput == "exit") {
            break;
        }
        if (validateCommand(userInput)) {
            std::string output = executeCommand(userInput);
            std::cout << "Output: " << output << std::endl;
        } else {
            std::cout << "Invalid or potentially dangerous command. Please try again." << std::endl;
        }
    }
    return 0;
}
