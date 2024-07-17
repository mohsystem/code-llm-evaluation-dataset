#include <iostream>
#include <string>

std::string tweakLetters(std::string s, int tweaks[]) {
    std::string result = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i] + tweaks[i];
        if (c < 'a') {
            c += 26;
        } else if (c > 'z') {
            c -= 26;
        }
        result += c;
    }
    return result;
}

int main() {
    std::cout << tweakLetters("apple", new int[]{0, 1, -1, 0, -1}) << std::endl; // "aqold"
    std::cout << tweakLetters("many", new int[]{0, 0, 0, -1}) << std::endl; // "manx"
    std::cout << tweakLetters("rhino", new int[]{1, 1, 1, 1, 1}) << std::endl; // "sijop"
    return 0;
}