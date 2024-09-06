// C++
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string fileName;
    std::cout << "Enter file name: ";
    std::getline(std::cin, fileName);

    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }

    return 0;
}