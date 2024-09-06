
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    std::ifstream file("input.txt");
    std::regex pattern("^\\\\d+.*\\\\.$");
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (std::regex_match(line, pattern)) {
                std::cout << line << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }

    return 0;
}
