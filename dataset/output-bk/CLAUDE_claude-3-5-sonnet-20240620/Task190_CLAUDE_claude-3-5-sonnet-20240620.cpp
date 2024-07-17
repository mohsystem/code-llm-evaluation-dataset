
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    std::ifstream file("file.txt");
    std::vector<std::vector<std::string>> data;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    for (size_t j = 0; j < data[0].size(); ++j) {
        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << data[i][j];
            if (i < data.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
