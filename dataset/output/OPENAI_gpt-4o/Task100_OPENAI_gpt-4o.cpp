#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <pattern> <filename>" << std::endl;
        return 1;
    }

    std::string pattern = argv[1];
    std::string filename = argv[2];
    std::ifstream file(filename);
    if (!file.isOpened()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::regex regexPattern(pattern);
    std::smatch match;
    std::vector<std::string> matches;

    std::string::const_iterator searchStart(content.cbegin());
    while (std::regex_search(searchStart, content.cend(), match, regexPattern)) {
        matches.push_back(match[0]);
        searchStart = match.suffix().first;
    }

    for (const auto &m : matches)
        std::cout << m << std::endl;

    return 0;
}