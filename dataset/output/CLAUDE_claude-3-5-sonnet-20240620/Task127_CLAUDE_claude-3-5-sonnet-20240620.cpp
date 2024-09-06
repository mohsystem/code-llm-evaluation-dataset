
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdexcept>

namespace fs = std::filesystem;

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
        std::cout << "File copied successfully from " << sourcePath << " to " << destPath << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::string sourceFile = "source.txt";
    std::string tempDir = "temp";
    std::string tempFile = tempDir + fs::path::preferred_separator + "temp_copy.txt";

    try {
        fs::create_directories(tempDir);
        copyFile(sourceFile, tempFile);
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error creating temporary directory: " << e.what() << std::endl;
    }

    try {
        if (fs::exists(tempFile)) {
            fs::remove(tempFile);
            std::cout << "Temporary file " << tempFile << " removed." << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error removing temporary file: " << e.what() << std::endl;
    }

    try {
        if (fs::exists(tempDir)) {
            fs::remove_all(tempDir);
            std::cout << "Temporary directory " << tempDir << " removed." << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error removing temporary directory: " << e.what() << std::endl;
    }

    return 0;
}
