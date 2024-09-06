#include <iostream>
#include <fstream>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./program <filename>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    
    if (!std::filesystem::exists(filename)) {
        std::cout << "File does not exist" << std::endl;
        return 1;
    }
    
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    return 0;
}