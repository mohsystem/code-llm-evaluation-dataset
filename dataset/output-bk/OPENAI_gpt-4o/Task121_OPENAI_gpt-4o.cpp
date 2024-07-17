#include <iostream>
#include <fstream>
#include <filesystem>

int main() {
    std::string filename, content, line;
    
    std::cout << "Enter the file name: ";
    std::getline(std::cin, filename);
    std::cout << "Enter the file content (end with EOF): ";
    while (std::getline(std::cin, line)) {
        content += line + "
";
    }

    std::ofstream ofs("uploads/" + filename, std::ios::binary);
    if (ofs.is_open()) {
        ofs << content;
        ofs.close();
        std::cout << "File uploaded successfully" << std::endl;
    } else {
        std::cout << "No file uploaded" << std::endl;
    }

    return 0;
}