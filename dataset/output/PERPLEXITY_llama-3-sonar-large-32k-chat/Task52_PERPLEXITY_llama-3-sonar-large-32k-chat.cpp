// C++ code
#include <fstream>
#include <iostream>

std::string caesarEncrypt(const std::string& text, int shift) {
    std::string result;

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char) ((c - base + shift) % 26 + base);
        } else {
            result += c;
        }
    }

    return result;
}

std::string caesarDecrypt(const std::string& text, int shift) {
    std::string result;

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char) ((c - base - shift) % 26 + base);
        } else {
            result += c;
        }
    }

    return result;
}

void encryptFile(const std::string& filePath, int shift) {
    std::ifstream file(filePath);
    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::string encryptedText = caesarEncrypt(text, shift);

    std::ofstream writer(filePath);
    writer << encryptedText;
    writer.close();
}

void decryptFile(const std::string& filePath, int shift) {
    std::ifstream file(filePath);
    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::string decryptedText = caesarDecrypt(text, shift);

    std::ofstream writer(filePath);
    writer << decryptedText;
    writer.close();
}

int main() {
    std::string filePath = "example.txt";
    int shift = 3;
    encryptFile(filePath, shift);
    decryptFile(filePath, shift);
    return 0;
}