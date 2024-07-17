#include <iostream>
#include <cstdlib>

int main() {
    std::string command;
    std::cout << "Enter a command to run: ";
    std::getline(std::cin, command);
    system(command.c_str());
    return 0;
}