
#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);

    std::string command = "cat " + filename;
    int result = system(command.c_str());

    if (result != 0) {
        std::cerr << "Error executing command" << std::endl;
        return 1;
    }

    return 0;
}
