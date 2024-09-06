#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream file("file.txt");
    std::vector<std::vector<std::string>> lines;
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string field;
        while (ss >> field) {
            row.push_back(field);
        }
        lines.push_back(row);
    }
    std::vector<std::vector<std::string>> transposed(lines[0].size(), std::vector<std::string>());
    for (size_t i = 0; i < lines.size(); i++) {
        for (size_t j = 0; j < lines[i].size(); j++) {
            transposed[j].push_back(lines[i][j]);
        }
    }
    for (const auto& row : transposed) {
        for (const auto& field : row) {
            std::cout << field << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}