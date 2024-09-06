#include <iostream>
#include <fstream>

int main() {
    try {
        std::ifstream source("source_file.txt", std::ios::binary);
        std::ofstream dest("destination_file.txt", std::ios::binary);

        if (!source.is_open() || !dest.is_open()) {
            throw std::runtime_error("Failed to open files.");
        }

        dest << source.rdbuf();

        source.close();
        dest.close();
    } catch (const std::exception& e) {
        std::cout << "An error occurred: " << e.what() << '\n';
    }

    return 0;
}