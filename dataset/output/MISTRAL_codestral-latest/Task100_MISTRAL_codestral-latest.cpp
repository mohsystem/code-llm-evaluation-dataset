#include <iostream>
#include <fstream>
#include <regex>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <pattern> <filename>
";
        return 1;
    }

    const std::string pattern = argv[1];
    const std::string filename = argv[2];

    std::regex regex(pattern);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file
";
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (std::regex_search(line, regex)) {
            std::cout << "Match found: " << line << '
';
        }
    }

    file.close();

    return 0;
}