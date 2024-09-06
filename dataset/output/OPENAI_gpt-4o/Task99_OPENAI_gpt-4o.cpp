#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    std::string filename = "input.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return 1;
    }

    std::regex pattern("^\\d.*\\.$");
    std::string line;
    
    while (std::getline(file, line)) {
        if (std::regex_match(line, pattern)) {
            std::cout << line << std::endl;
        }
    }

    file.close();
    return 0;
}