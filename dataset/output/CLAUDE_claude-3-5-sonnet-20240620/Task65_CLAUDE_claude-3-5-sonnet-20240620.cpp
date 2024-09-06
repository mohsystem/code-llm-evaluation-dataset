
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void readFile(const std::string& filename) {
    if (filename.substr(filename.length() - 4) != ".txt") {
        std::cout << "Error: File must have a .txt extension" << std::endl;
        return;
    }

    if (!std::filesystem::exists(filename)) {
        std::cout << "Error: File '" << filename << "' does not exist" << std::endl;
        return;
    }

    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::cout << "File contents:" << std::endl;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Error: Unable to read file '" << filename << "'" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    } else {
        readFile(argv[1]);
    }
    return 0;
}
