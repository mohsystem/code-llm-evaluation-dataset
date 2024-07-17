#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string fileName;
    std::cout << "Enter file name: ";
    std::getline(std::cin, fileName);
    std::ifstream file(fileName);
    if (!file) {
        std::cout << "Error reading file: " << fileName << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}