#include <iostream>
#include <fstream>
#include <regex>

void match_lines(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    std::regex pattern(R"(^[0-9].*\.$)");
    std::string line;
    while (std::getline(file, line)) {
        if (std::regex_match(line, pattern)) {
            std::cout << line << std::endl;
        }
    }

    file.close();
}

int main() {
    const std::string file_name = "input.txt";
    match_lines(file_name);
    return 0;
}