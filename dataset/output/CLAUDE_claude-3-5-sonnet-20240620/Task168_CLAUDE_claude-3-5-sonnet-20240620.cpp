
#include <iostream>
#include <string>
#include <vector>

std::string tweakLetters(const std::string& word, const std::vector<int>& arr) {
    std::string result = word;
    for (size_t i = 0; i < word.length() && i < arr.size(); ++i) {
        result[i] = ((word[i] - \'a\' + arr[i] + 26) % 26) + \'a\';
    }
    return result;
}

int main() {
    std::cout << tweakLetters("apple", {0, 1, -1, 0, -1}) << std::endl;
    std::cout << tweakLetters("many", {0, 0, 0, -1}) << std::endl;
    std::cout << tweakLetters("rhino", {1, 1, 1, 1, 1}) << std::endl;
    return 0;
}
