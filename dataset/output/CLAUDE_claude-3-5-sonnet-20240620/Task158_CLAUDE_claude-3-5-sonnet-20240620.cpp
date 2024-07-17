
#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    std::string userInput;
    std::cout << "Enter data: ";
    std::getline(std::cin, userInput);
    
    std::string command = "echo " + userInput;
    system(command.c_str());
    
    return 0;
}
