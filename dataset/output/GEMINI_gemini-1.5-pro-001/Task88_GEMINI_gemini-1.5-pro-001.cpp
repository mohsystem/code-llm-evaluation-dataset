#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <filesystem> // Requires C++17 or later

std::string createTempFileWithUnicode() {
    try {
        // Create a temporary file
        std::string tempFilePath = std::filesystem::temp_directory_path().string() + "/temp_" + std::to_string(rand()) + ".txt";
        std::ofstream tempFile(tempFilePath, std::ios::out | std::ios::binary);

        // Generate a random string
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<char> distribution('a', 'z');
        std::string randomString(10, ' '); // Create a string of length 10
        for (char& c : randomString) {
            c = distribution(generator);
        }

        // Write the string to the file (already in Unicode)
        tempFile << randomString;
        tempFile.close();

        return tempFilePath;

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return "";
    }
}

int main() {
    std::string tempFilePath = createTempFileWithUnicode();
    if (!tempFilePath.empty()) {
        std::cout << "Temporary file created at: " << tempFilePath << std::endl;
    }

    return 0;
}