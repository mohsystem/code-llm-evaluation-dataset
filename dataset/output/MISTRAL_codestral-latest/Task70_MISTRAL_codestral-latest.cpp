#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return "File not found.";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./program <file_path>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    std::string content = readFile(filePath);
    std::cout << content << std::endl;

    return 0;
}