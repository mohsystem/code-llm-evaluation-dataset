#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <regex_pattern> <file_name>" << std::endl;
        return 1;
    }

    const std::string pattern = argv[1];
    const std::string file_name = argv[2];

    try {
        std::regex regex(pattern);
        std::ifstream file(file_name);

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << file_name << std::endl;
            return 1;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (std::regex_search(line, regex)) {
                std::cout << line << std::endl;
            }
        }
    } catch (const std::regex_error& e) {
        std::cerr << "Invalid regex pattern: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}