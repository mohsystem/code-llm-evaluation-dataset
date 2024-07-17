#include <iostream>
#include <cstdio>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please provide the file path as an argument." << std::endl;
        return 1;
    }
    if (std::remove(argv[1]) == 0) {
        std::cout << "File deleted successfully." << std::endl;
    } else {
        std::perror("Error deleting the file");
    }
    return 0;
}