#include <iostream>
#include <cstdlib>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);
    std::string command = "cat " + filename;
    std::system(command.c_str());
    return 0;
}