#include <iostream>
#include <cstdlib>
#include <array>
#include <memory>

int main() {
    std::string command;
    std::cout << "Enter a bash command: ";
    std::getline(std::cin, command);

    std::shared_ptr<FILE> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        std::cerr << "An error occurred during execution." << std::endl;
        return 1;
    }
    std::array<char, 128> buffer;
    std::string result;
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    std::cout << "Command output: " << result << std::endl;
    return 0;
}