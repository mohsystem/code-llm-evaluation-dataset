#include <iostream>
#include <fstream>

int main() {
    const char* sourceFile = "/path/to/source/file";
    const char* destinationFile = "/path/to/destination/file";

    std::ifstream source(sourceFile, std::ios::binary);
    std::ofstream destination(destinationFile, std::ios::binary);

    if (source.is_open() && destination.is_open()) {
        destination << source.rdbuf();
        std::cout << "File copied successfully." << std::endl;
    } else {
        std::cout << "An error occurred." << std::endl;
    }

    source.close();
    destination.close();

    return 0;
}