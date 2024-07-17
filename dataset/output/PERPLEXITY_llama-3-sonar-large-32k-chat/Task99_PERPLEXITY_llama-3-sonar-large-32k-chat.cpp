#include <iostream>
#include <fstream>
#include <regex>

int main() {
    std::ifstream file("input.txt");
    std::regex pattern("^[0-9]+.*\\.$");
    std::string line;

    while (std::getline(file, line)) {
        if (std::regex_match(line, pattern)) {
            std::cout << line << std::endl;
        }
    }

    file.close();
    return 0;
}