#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream file("records.txt");
    
    if (!file.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }
    
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    
    std::sort(lines.begin(), lines.end(), [](const std::string &a, const std::string &b) {
        return a < b;
    });
    
    for (const auto &l : lines) {
        std::cout << l << std::endl;
    }
    
    return 0;
}