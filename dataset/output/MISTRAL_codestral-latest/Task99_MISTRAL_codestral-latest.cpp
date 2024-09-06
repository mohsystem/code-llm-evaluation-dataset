#include <iostream>
#include <fstream>
#include <regex>

int main() {
    std::ifstream file("path_to_your_file.txt");
    if (file.is_open()) {
        std::string line;
        std::regex pattern("^\\d.*\\.$");
        while (std::getline(file, line)) {
            if (std::regex_match(line, pattern)) {
                std::cout << line << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
    return 0;
}