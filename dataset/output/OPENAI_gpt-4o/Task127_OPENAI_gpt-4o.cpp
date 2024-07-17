#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main() {
    std::string sourcePath = "source.txt";
    std::string destinationPath = "/tmp/destination.txt";

    try {
        std::ifstream sourceFile(sourcePath, std::ios::binary);
        if (!sourceFile.is_open()) {
            throw std::ios_base::failure("The source file does not exist.");
        }

        std::ofstream destinationFile(destinationPath, std::ios::binary);
        if (!destinationFile.is_open()) {
            throw std::ios_base::failure("An error occurred while opening the destination file.");
        }

        destinationFile << sourceFile.rdbuf();
        sourceFile.close();
        destinationFile.close();

        std::cout << "File copied successfully in C++!" << std::endl;
    } catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}