#include <fstream>
#include <iostream>

int main() {
    std::string srcDir = "/path/to/source/directory";
    std::string dstDir = "/path/to/temporary/directory";
    std::string filename = "file.txt";

    try {
        std::ifstream srcFile(srcDir + "/" + filename, std::ios::binary);
        std::ofstream dstFile(dstDir + "/" + filename, std::ios::binary);

        if (!srcFile) {
            throw std::std::runtime_error("Error: File " + filename + " not found in " + srcDir);
        }

        dstFile << srcFile.rdbuf();

        std::cout << "File " << filename << " has been copied to " << dstDir << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}