
#include <iostream>
#include <cstdio>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];

    if (std::remove(filePath.c_str()) == 0) {
        std::cout << "File '" << filePath << "' has been deleted successfully." << std::endl;
    } else {
        std::perror("Error");
        std::cout << "Unable to delete '" << filePath << "'." << std::endl;
    }

    return 0;
}
