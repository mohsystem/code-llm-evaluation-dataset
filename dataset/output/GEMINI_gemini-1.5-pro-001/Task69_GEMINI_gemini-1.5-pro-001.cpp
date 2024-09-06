#include <iostream>
#include <fstream>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: delete_file <file_path>" << std::endl;
        return 1;
    }

    std::filesystem::path filePath = argv[1];

    if (!std::filesystem::exists(filePath)) {
        std::cerr << "Error: File '" << filePath << "' not found." << std::endl;
        return 1;
    }

    try {
        std::filesystem::remove(filePath);
        std::cout << "File '" << filePath << "' deleted successfully." << std::endl;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error deleting file '" << filePath << "': " << e.what() << std::endl;
        return 1;
    }

    return 0;
}