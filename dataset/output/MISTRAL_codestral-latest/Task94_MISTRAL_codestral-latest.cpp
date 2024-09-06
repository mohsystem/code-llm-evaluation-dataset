// CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> records;
    std::ifstream file("file.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            records.push_back(line);
        }
        file.close();
    }
    std::sort(records.begin(), records.end());
    for (const auto &record : records) {
        std::cout << record << std::endl;
    }
    return 0;
}