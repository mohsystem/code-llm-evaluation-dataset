#include <iostream>
#include <fstream>
#include <string>

bool isValidFilename(const std::string& filename) {
    // Add your filename validation logic here
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    if (!isValidFilename(filename)) {
        std::cout << "Invalid filename format" << std::endl;
        return 1;
    }
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File does not exist or is inaccessible" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}