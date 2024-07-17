
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <regex_pattern> <file_name>" << std::endl;
        return 1;
    }

    std::string regexPattern = argv[1];
    std::string fileName = argv[2];

    try {
        std::regex pattern(regexPattern);
        std::ifstream file(fileName);

        if (!file.is_open()) {
            std::cerr << "Could not open file " << fileName << std::endl;
            return 1;
        }

        std::string line;
        int lineNumber = 0;

        while (std::getline(file, line)) {
            lineNumber++;
            std::smatch match;
            std::string::const_iterator searchStart(line.cbegin());

            while (std::regex_search(searchStart, line.cend(), match, pattern)) {
                std::cout << "Line " << lineNumber << ": " << match.str() << std::endl;
                searchStart = match.suffix().first;
            }
        }

        file.close();
    }
    catch (const std::regex_error& e) {
        std::cerr << "Regex error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
