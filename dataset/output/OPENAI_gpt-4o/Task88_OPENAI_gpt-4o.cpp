#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <filesystem>
#include <locale>
#include <codecvt>

int main() {
    // Generate a random string
    std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string randomString;
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, characters.size() - 1);
    for (int i = 0; i < 10; ++i) {
        randomString += characters[dist(rng)];
    }

    // Convert string into Unicode
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring unicodeString = converter.from_bytes(randomString);

    // Create a temporary file and write the Unicode string to it
    std::filesystem::path tempFile = std::filesystem::temp_directory_path() / std::filesystem::unique_path();
    std::wofstream file(tempFile.c_str());
    file.imbue(std::locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t>));
    file << unicodeString;
    file.close();

    // Output the path of the temporary file
    std::wcout << tempFile << std::endl;

    return 0;
}