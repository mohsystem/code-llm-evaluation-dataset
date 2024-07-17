#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Record {
    std::string key;
    std::string value;
};

bool compare(const Record &a, const Record &b) {
    return a.key < b.key;
}

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::vector<Record> records;
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find('-');
        Record record;
        record.key = line.substr(0, pos);
        record.value = line.substr(pos + 1);
        records.push_back(record);
    }
    std::sort(records.begin(), records.end(), compare);
    for (const auto &record : records) {
        std::cout << record.key << "-" << record.value << std::endl;
    }
    file.close();
    return 0;
}