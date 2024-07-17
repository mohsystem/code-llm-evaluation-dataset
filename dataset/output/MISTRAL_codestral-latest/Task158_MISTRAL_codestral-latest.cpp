#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    // Get user input
    std::string userInput;
    std::cout << "Enter data for OS command: ";
    std::getline(std::cin, userInput);

    // Run OS command with user input
    std::string command = "your_command " + userInput;
    std::system(command.c_str());

    return 0;
}