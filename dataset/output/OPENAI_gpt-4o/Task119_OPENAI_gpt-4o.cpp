#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void readCSV(const std::string &filePath) {
    std::ifstream file(filePath);
    std::string line, word;
    
    while (std::getline(file, line)) {
        std::stringstream s(line);
        while (std::getline(s, word, ',')) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}

void writeCSV(const std::string &filePath, const std::vector<std::vector<std::string>> &data) {
    std::ofstream file(filePath);

    for (const auto &row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i != row.size() - 1) file << ",";
        }
        file << "\n";
    }
}

int main() {
    std::vector<std::vector<std::string>> data = {
        {"Name", "Age", "City"},
        {"Alice", "30", "New York"},
        {"Bob", "25", "Los Angeles"},
        {"Charlie", "35", "Chicago"}
    };

    std::string filePath = "example.csv";

    writeCSV(filePath, data);
    readCSV(filePath);

    return 0;
}