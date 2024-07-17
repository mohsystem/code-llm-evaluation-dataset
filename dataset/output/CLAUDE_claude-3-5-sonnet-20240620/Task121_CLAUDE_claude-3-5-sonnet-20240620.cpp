
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void uploadFile() {
    std::string filename;
    std::cout << "Enter the filename to upload: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename, std::ios::binary);
    if (file) {
        std::vector<char> content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        std::cout << "File \'" << filename << "\' uploaded successfully." << std::endl;
        std::cout << "File size: " << content.size() << " bytes" << std::endl;
    } else {
        std::cout << "File \'" << filename << "\' not found." << std::endl;
    }
}

int main() {
    uploadFile();
    return 0;
}
