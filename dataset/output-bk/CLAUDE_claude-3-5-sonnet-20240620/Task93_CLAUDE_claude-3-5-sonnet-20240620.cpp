
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::map<std::string, std::string> sortedMap;
    std::string line;

    while (std::getline(file, line)) {
        size_t colonPos = line.find(\':\');
        if (colonPos != std::string::npos) {
            std::string key = line.substr(0, colonPos);
            std::string value = line.substr(colonPos + 1);
            sortedMap[key] = value;
        }
    }

    file.close();

    for (const auto &pair : sortedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
