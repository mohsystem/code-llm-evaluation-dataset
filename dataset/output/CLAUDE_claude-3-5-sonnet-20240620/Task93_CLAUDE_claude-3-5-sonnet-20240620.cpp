
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

void read_and_sort_records(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file '" << filename << "'" << std::endl;
        return;
    }

    std::map<std::string, std::string> records;
    std::string line;

    while (std::getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            key.erase(0, key.find_first_not_of(" \\t"));
            key.erase(key.find_last_not_of(" \\t") + 1);
            value.erase(0, value.find_first_not_of(" \\t"));
            value.erase(value.find_last_not_of(" \\t") + 1);
            records[key] = value;
        } else {
            std::cerr << "Warning: Skipping invalid line: " << line << std::endl;
        }
    }

    for (const auto& record : records) {
        std::cout << record.first << ": " << record.second << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    read_and_sort_records(argv[1]);
    return 0;
}
