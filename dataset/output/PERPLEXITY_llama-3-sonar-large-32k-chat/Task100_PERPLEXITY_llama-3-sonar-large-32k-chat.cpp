#include <iostream>
#include <fstream>
#include <regex>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <pattern> <file>" << std::endl;
        return 1;
    }
    std::string pattern = argv[1];
    std::string file = argv[2];
    std::regex regex(pattern);
    std::ifstream fp(file);
    if (!fp) {
        std::cout << "Could not open file" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(fp, line)) {
        std::smatch match;
        while (std::regex_search(line, match, regex)) {
            std::cout << match.str() << std::endl;
            line = match.suffix();
        }
    }
    fp.close();
    return 0;
}