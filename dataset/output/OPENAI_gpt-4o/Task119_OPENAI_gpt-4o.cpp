#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void processCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "File opening failed
";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        while (std::getline(lineStream, cell, ',')) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    file.close();
}

int main() {
    processCSV("data.csv");
    return 0;
}