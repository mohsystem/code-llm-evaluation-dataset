// C++
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream file("file.csv");
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            // Process cell here
        }
    }
    return 0;
}