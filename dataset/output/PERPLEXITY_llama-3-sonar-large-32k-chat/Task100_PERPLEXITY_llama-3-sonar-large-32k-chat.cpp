#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " pattern file_name" << std::endl;
        return 1;
    }

    std::string pattern = argv[1];
    std::string file_name = argv[2];

    std::ifstream file(file_name);
    if (!file) {
        std::cerr << "Failed to open file " << file_name << std::endl;
        return 1;
    }

    std::regex re(pattern);
    std::string line;
    while (std::getline(file, line)) {
        std::smatch match;
        while (std::regex_search(line, match, re)) {
            std::cout << match.str() << std::endl;
            line = match.suffix();
        }
    }

    return 0;
}