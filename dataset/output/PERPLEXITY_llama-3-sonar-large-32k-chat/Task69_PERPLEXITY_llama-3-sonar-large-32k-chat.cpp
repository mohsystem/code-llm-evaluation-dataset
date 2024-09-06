#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./delete_file <file_path>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];

    if (std::remove(filePath.c_str()) != 0) {
        std::cout << "Failed to delete the file" << std::endl;
    } else {
        std::cout << "File deleted successfully" << std::endl;
    }

    return 0;
}