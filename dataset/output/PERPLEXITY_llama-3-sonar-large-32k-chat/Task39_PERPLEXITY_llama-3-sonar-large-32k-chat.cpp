#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string filename;
    std::cout << "Enter a filename: ";
    std::cin >> filename;
    std::string command = "cat " + filename;
    system(command.c_str());
    return 0;
}