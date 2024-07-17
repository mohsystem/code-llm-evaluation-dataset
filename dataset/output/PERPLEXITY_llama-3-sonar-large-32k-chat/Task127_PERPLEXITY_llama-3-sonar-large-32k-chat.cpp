#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void copyFile(const std::string& srcDir, const std::string& srcFile, const std::string& dstDir) {
    try {
        fs::path srcPath = srcDir + "/" + srcFile;
        fs::path dstPath = dstDir + "/" + srcFile;
        fs::copy_file(srcPath, dstPath);
        std::cout << "File " << srcFile << " copied successfully to " << dstDir << std::endl;
    } catch (const fs::filesystem_error& e) {
        if (e.code().value() == ENOENT) {
            std::cout << "Error: File " << srcFile << " not found in " << srcDir << std::endl;
        } else if (e.code().value() == EACCES) {
            std::cout << "Error: Permission denied to read file " << srcFile << " in " << srcDir << " or write to " << dstDir << std::endl;
        } else {
            std::cout << "An error occurred: " << e.what() << std::endl;
        }
    }
}

int main() {
    std::string srcDir = "/path/to/source/directory";
    std::string srcFile = "file.txt";
    std::string dstDir = "/path/to/temporary/directory";
    copyFile(srcDir, srcFile, dstDir);
    return 0;
}