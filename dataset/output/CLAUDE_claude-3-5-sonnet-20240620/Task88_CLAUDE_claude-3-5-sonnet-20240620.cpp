
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <filesystem>
#include <codecvt>
#include <locale>

namespace fs = std::filesystem;

std::string create_temp_file_with_unicode() {
    // Create a temporary file
    fs::path temp_path = fs::temp_directory_path() / fs::path("temp_file.txt");
    std::ofstream temp_file(temp_path, std::ios::out | std::ios::binary);

    // Generate a random string
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);
    std::string random_string;
    for (int i = 0; i < 10; ++i) {
        random_string += chars[dis(gen)];
    }

    // Convert the string to Unicode
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wide_string = converter.from_bytes(random_string);
    std::string unicode_string;
    for (wchar_t c : wide_string) {
        char buf[7];
        snprintf(buf, sizeof(buf), "\\\\u%04X", c);
        unicode_string += buf;
    }

    // Write the Unicode string to the file
    temp_file << unicode_string;
    temp_file.close();

    return temp_path.string();
}

int main() {
    std::cout << create_temp_file_with_unicode() << std::endl;
    return 0;
}
