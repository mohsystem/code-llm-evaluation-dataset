#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void process_csv(const std::string& file_name) {
    std::ifstream file(file_name);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    process_csv("your_file.csv");
    return 0;
}