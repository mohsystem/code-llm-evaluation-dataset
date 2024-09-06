#include <iostream>
#include <filesystem>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    std::filesystem::path file_path = argv[1];

    try {
        if (std::filesystem::remove(file_path)) {
            std::cout << file_path << " deleted successfully." << std::endl;
        } else {
            std::cerr << file_path << " does not exist." << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}