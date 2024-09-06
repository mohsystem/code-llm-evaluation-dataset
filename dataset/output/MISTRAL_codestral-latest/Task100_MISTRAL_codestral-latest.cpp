#include <iostream>
#include <fstream>
#include <regex>

int main(int argc, char* argv[]) {
    std::string pattern = argv[1];
    std::string fileName = argv[2];

    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string line;
        std::regex regexPattern(pattern);

        while (std::getline(file, line)) {
            std::smatch match;
            while (std::regex_search(line, match, regexPattern)) {
                std::cout << match.str() << std::endl;
                line = match.suffix().str();
            }
        }

        file.close();
    } else {
        std::cout << "File not found: " << fileName << std::endl;
    }

    return 0;
}