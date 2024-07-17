#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("data.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file
";
        return 1;
    }

    std::vector<std::string> records;
    std::string line;
    while (std::getline(file, line)) {
        records.push_back(line);
    }
    file.close();

    std::sort(records.begin(), records.end());

    std::ofstream sorted_file("sorted_data.txt");
    if (!sorted_file.is_open()) {
        std::cerr << "Unable to open file
";
        return 1;
    }

    for (const auto &record : records) {
        sorted_file << record << '
';
    }

    return 0;
}