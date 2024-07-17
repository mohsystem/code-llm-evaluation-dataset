#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string data;
    std::cout << "Enter data: ";
    std::getline(std::cin, data);
    std::string command = "echo " + data + " > output.txt";
    system(command.c_str());
    return 0;
}