#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdexcept>

void copy_file(const std::string &source_path, const std::string &dest_path) {
    std::ifstream source(source_path, std::ios::binary);
    std::ofstream dest(dest_path, std::ios::binary);

    if (!source.is_open()) {
        throw std::runtime_error("Error: The file at " + source_path + " does not exist.");
    }

    if (!dest.is_open()) {
        throw std::runtime_error("Error: Unable to open destination file.");
    }

    dest << source.rdbuf();
}

int main() {
    std::string source_path = "/path/to/source/file.txt";
    std::string dest_path = "/path/to/dest/tmp_file.txt";

    try {
        copy_file(source_path, dest_path);
        std::cout << "File copied successfully." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
    }

    return 0;
}