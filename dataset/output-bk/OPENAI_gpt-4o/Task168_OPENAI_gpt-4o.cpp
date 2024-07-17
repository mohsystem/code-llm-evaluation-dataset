#include <iostream>
#include <vector>

std::string tweakLetters(const std::string &txt, const std::vector<int> &arr) {
    std::string result = txt;
    for (std::size_t i = 0; i < txt.size(); ++i) {
        result[i] = txt[i] + arr[i];
    }
    return result;
}

int main() {
    std::cout << tweakLetters("apple", {0, 1, -1, 0, -1}) << std::endl;
    std::cout << tweakLetters("many", {0, 0, 0, -1}) << std::endl;
    std::cout << tweakLetters("rhino", {1, 1, 1, 1, 1}) << std::endl;
    return 0;
}