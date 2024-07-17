#include <iostream>
#include <fstream>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: File path not provided." << std::endl;
        return 1;
    }

    std::string filePath = argv[1];

    if (std::filesystem::remove(filePath)) {
        std::cout << "File deleted successfully." << std::endl;
    } else {
        std::cerr << "Failed to delete the file. File may not exist." << std::endl;
        return 1;
    }

    return 0;
}