// C++
#include <iostream>
#include <string>
#include <cctype>

std::string encrypt(std::string text, int s) {
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            text[i] = (text[i] + s - 65) % 26 + 65;
        else
            text[i] = (text[i] + s - 97) % 26 + 97;
    }

    return text;
}

int main() {
    std::string text = "HELLO";
    int s = 4;
    std::cout << "Text : " << text << std::endl;
    std::cout << "Shift : " << s << std::endl;
    std::cout << "Cipher: " << encrypt(text, s) << std::endl;
    return 0;
}