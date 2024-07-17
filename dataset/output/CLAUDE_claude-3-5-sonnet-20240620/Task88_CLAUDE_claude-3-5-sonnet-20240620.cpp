
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <codecvt>
#include <locale>
#include <cstdio>

std::string generate_random_string(int length) {
    const std::string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, charset.length() - 1);

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += charset[dis(gen)];
    }
    return result;
}

std::wstring convert_to_unicode(const std::string& input) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(input);
}

int main() {
    char temp_filename[] = "unicode_XXXXXX";
    int fd = mkstemp(temp_filename);
    if (fd == -1) {
        std::cerr << "Failed to create temporary file" << std::endl;
        return 1;
    }

    std::wofstream temp_file(temp_filename, std::ios::out | std::ios::binary);
    temp_file.imbue(std::locale(temp_file.getloc(), new std::codecvt_utf8<wchar_t>));

    if (!temp_file.is_open()) {
        std::cerr << "Failed to open temporary file" << std::endl;
        close(fd);
        return 1;
    }

    std::string random_string = generate_random_string(10);
    std::wstring unicode_string = convert_to_unicode(random_string);

    temp_file << unicode_string;
    temp_file.close();

    std::cout << "Temporary file path: " << temp_filename << std::endl;

    return 0;
}
