#include <fstream>
#include <iostream>

void uploadFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    std::ofstream outputFile("uploaded_" + filePath.substr(filePath.find_last_of("/\\") + 1), std::ios::binary);
    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    char* buffer = new char[fileSize];
    file.read(buffer, fileSize);
    outputFile.write(buffer, fileSize);
    delete[] buffer;
    file.close();
    outputFile.close();
}

int main() {
    std::cout << "Enter the file path: ";
    std::string filePath;
    std::getline(std::cin, filePath);
    uploadFile(filePath);
    std::cout << "File uploaded successfully!" << std::endl;
    return 0;
}