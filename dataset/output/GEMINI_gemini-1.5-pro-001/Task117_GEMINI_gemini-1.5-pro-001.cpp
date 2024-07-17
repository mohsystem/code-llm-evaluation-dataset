#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string archiveFile, outputDir, filePath;

    std::cout << "Enter the path to the archive file: ";
    std::getline(std::cin, archiveFile);

    std::cout << "Enter the directory to extract to (leave blank to extract to current directory): ";
    std::getline(std::cin, outputDir);

    if (outputDir.empty()) {
        outputDir = ".";
    }

    if (archiveFile.find(".zip") != std::string::npos) {
        // Extracting from ZIP archives is not directly supported in standard C++
        // You would need to use external libraries like zlib
        std::cerr << "ZIP extraction is not supported in this example. Please use external libraries like zlib." << std::endl;
        return 1; 
    } else {
        std::cerr << "Unsupported archive format." << std::endl;
        return 1; 
    }

    return 0;
}