#include <iostream>
#include <string>
#include <algorithm>

std::string longest(std::string s1, std::string s2) {
    std::string result = s1 + s2;
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
}

int main() {
    std::cout << longest("xyaabbbccccdefww", "xxxxyyyyabklmopq") << std::endl;
    std::cout << longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz") << std::endl;
    return 0;
}