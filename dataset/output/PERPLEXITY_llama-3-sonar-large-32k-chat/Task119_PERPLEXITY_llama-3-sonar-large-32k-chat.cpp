#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void parseCSV(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    file.close();
}

int main() {
    parseCSV("example.csv");
    return 0;
}