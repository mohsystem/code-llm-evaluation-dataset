#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    // Get user input
    std::string userInput;
    std::cout << "Enter data for OS command: ";
    std::getline(std::cin, userInput);

    // Construct the OS command
    std::string command = "your_command_here " + userInput;

    // Execute the command
    std::system(command.c_str());

    return 0;
}