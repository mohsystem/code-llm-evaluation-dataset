#include <iostream>
#include <fstream>
#include <regex>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    std::regex pattern("^\\d+.*\\.$");
    while (std::getline(file, line)) {
        if (std::regex_match(line, pattern)) {
            std::cout << line << std::endl;
        }
    }
    return 0;
}