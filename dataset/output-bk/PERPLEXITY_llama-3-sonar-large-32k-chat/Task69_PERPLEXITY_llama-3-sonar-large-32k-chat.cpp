#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }
    if (std::remove(argv[1]) == 0) {
        std::cout << "File deleted successfully" << std::endl;
    } else {
        std::cout << "Failed to delete the file" << std::endl;
    }
    return 0;
}