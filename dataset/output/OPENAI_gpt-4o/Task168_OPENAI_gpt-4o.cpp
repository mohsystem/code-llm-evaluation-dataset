#include <iostream>
#include <vector>
#include <string>

std::string tweakLetters(const std::string& s, const std::vector<int>& arr) {
    std::string result;
    result.reserve(s.length());
    for (size_t i = 0; i < s.length(); ++i) {
        result += (char)( ((s[i] - 'a' + arr[i]) % 26 + 26) % 26 + 'a' );
    }
    return result;
}

int main() {
    std::cout << tweakLetters("apple", {0, 1, -1, 0, -1}) << std::endl;  // "aqold"
    std::cout << tweakLetters("many", {0, 0, 0, -1}) << std::endl;       // "manx"
    std::cout << tweakLetters("rhino", {1, 1, 1, 1, 1}) << std::endl;    // "sijop"
    return 0;
}