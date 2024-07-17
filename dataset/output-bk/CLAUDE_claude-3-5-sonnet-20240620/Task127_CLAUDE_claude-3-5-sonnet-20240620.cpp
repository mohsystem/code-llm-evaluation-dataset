
#include <iostream>
#include <fstream>
#include <stdexcept>

void copyFile(const std::string& sourcePath, const std::string& destPath) {
    try {
        std::ifstream source(sourcePath, std::ios::binary);
        if (!source) {
            throw std::runtime_error("Source file not found: " + sourcePath);
        }

        std::ofstream dest(destPath, std::ios::binary);
        if (!dest) {
            throw std::runtime_error("Cannot create destination file: " + destPath);
        }

        dest << source.rdbuf();
        
        if (source.fail() || dest.fail()) {
            throw std::runtime_error("I/O error occurred during file copy");
        }

        std::cout << "File copied successfully from " << sourcePath << " to " << destPath << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::string sourcePath = "path/to/source/file.txt";
    std::string destPath = "/tmp/copied_file.txt";
    copyFile(sourcePath, destPath);
    return 0;
}
