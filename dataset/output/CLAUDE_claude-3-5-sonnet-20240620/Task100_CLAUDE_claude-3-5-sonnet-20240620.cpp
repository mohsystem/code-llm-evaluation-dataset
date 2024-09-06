
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <regex_pattern> <file_name>" << std::endl;
        return 1;
    }

    std::string pattern = argv[1];
    std::string fileName = argv[2];

    try {
        std::regex regex(pattern);
        std::ifstream file(fileName);
        std::string line;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                if (std::regex_search(line, regex)) {
                    std::cout << line << std::endl;
                }
            }
            file.close();
        } else {
            std::cout << "Unable to open file" << std::endl;
            return 1;
        }
    } catch (const std::regex_error& e) {
        std::cout << "Invalid regular expression: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
