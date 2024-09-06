// C++

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readAndSortFile(const std::string& filePath) {
    std::vector<std::string> records;
    std::string line;
    std::ifstream file(filePath);

    if (file.is_open()) {
        while (std::getline(file, line)) {
            records.push_back(line);
        }
        file.close();
        std::sort(records.begin(), records.end());
    } else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }

    return records;
}

int main() {
    std::vector<std::string> sortedRecords = readAndSortFile("path_to_your_file.txt");
    for (const auto& record : sortedRecords) {
        std::cout << record << std::endl;
    }
    return 0;
}