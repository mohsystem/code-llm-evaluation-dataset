
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void processCSV(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;

    if (std::getline(file, line)) {
        std::cout << "CSV Header: " << line << std::endl;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> row;
        std::string field;

        while (std::getline(iss, field, ',')) {
            row.push_back(field);
        }

        std::cout << "Row: ";
        for (const auto& item : row) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string filePath = "example.csv";
    processCSV(filePath);
    return 0;
}
