
#include <iostream>
#include <cstdio>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    const char *filePath = argv[1];

    if (std::remove(filePath) == 0) {
        std::cout << "File deleted successfully: " << filePath << std::endl;
    } else {
        std::cout << "Failed to delete the file: " << filePath << std::endl;
    }

    return 0;
}
