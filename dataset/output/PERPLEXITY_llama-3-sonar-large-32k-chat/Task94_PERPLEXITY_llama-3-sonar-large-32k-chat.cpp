code here:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("input.txt");
    std::vector<std::pair<std::string, std::string>> records;
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find("=");
        records.push_back({line.substr(0, pos), line.substr(pos + 1)});
    }
    file.close();
    std::sort(records.begin(), records.end());
    for (const auto& record : records) {
        std::cout << record.first << "=" << record.second << std::endl;
    }
    return 0;
}