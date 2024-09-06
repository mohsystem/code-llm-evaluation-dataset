#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    std::string command;
    std::cout << "Enter the command to execute: ";
    std::getline(std::cin, command);
    system(command.c_str());
    return 0;
}