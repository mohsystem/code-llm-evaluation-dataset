#include <iostream>
#include <fstream>
#include <regex>

int main() {
    std::ifstream file("file.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    std::regex pattern("^[0-9].*\\.$");

    while (std::getline(file, line)) {
        if (std::regex_match(line, pattern)) {
            std::cout << line << std::endl;
        }
    }

    file.close();

    return 0;
}