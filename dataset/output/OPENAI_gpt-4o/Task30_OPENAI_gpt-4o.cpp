#include <iostream>
#include <set>
#include <string>

std::string longest(const std::string &s1, const std::string &s2) {
    std::set<char> letters(s1.begin(), s1.end());
    letters.insert(s2.begin(), s2.end());
    return std::string(letters.begin(), letters.end());
}

int main() {
    std::cout << longest("xyaabbbccccdefww", "xxxxyyyyabklmopq") << std::endl; // "abcdefklmopqwxy"
    std::cout << longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz") << std::endl; // "abcdefghijklmnopqrstuvwxyz"
    return 0;
}