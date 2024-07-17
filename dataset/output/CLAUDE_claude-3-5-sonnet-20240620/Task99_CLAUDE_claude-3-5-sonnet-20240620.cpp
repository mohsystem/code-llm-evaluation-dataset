
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::regex pattern("^\\\\d+.*\\\\.$");
    std::string line;

    while (std::getline(file, line)) {
        if (std::regex_match(line, pattern)) {
            std::cout << line << std::endl;
        }
    }

    file.close();
    return 0;
}
