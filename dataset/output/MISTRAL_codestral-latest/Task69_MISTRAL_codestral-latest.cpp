#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string filePath = argv[1];
        std::filesystem::path path(filePath);

        if (std::filesystem::exists(path)) {
            if (std::filesystem::remove(path)) {
                std::cout << "File " << filePath << " has been deleted." << std::endl;
            } else {
                std::cout << "Failed to delete the file." << std::endl;
            }
        } else {
            std::cout << "File " << filePath << " does not exist." << std::endl;
        }
    } else {
        std::cout << "Please provide the file path as a command line argument." << std::endl;
    }

    return 0;
}