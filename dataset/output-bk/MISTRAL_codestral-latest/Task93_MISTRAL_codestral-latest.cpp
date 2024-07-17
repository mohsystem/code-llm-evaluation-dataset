#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> map;
    std::ifstream file("file.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find("=");
            if (pos != std::string::npos) {
                map[line.substr(0, pos)] = line.substr(pos + 1);
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
        return 1;
    }

    for (const auto &pair : map) {
        std::cout << pair.first << "=" << pair.second << '
';
    }

    return 0;
}