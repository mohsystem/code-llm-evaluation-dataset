#include <iostream>
#include <fstream>
#include <random>
#include <string>

std::string generate_random_string(size_t length) {
    std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> dist(0, charset.length() - 1);

    std::string randomString;
    for (size_t i = 0; i < length; ++i) {
        randomString += charset[dist(generator)];
    }
    return randomString;
}

int main() {
    // Generate random string
    std::string randomString = generate_random_string(7);

    // Convert string to Unicode
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::string unicodeString = converter.to_bytes(converter.from_bytes(randomString));

    // Create temporary file
    char tempFileName[] = "tempXXXXXX.txt";
    int fd = mkstemps(tempFileName, 4);

    std::ofstream tempFile(tempFileName, std::ofstream::out | std::ofstream::binary);
    
    // Write to the file
    tempFile << unicodeString;
    tempFile.close();
    
    // Return the path
    std::cout << "File path: " << tempFileName << std::endl;
    return 0;
}