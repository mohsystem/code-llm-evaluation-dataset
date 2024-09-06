#include <iostream>
#include <set>
#include <algorithm>

std::string longest(const std::string &s1, const std::string &s2) {
    std::set<char> charSet(s1.begin(), s1.end());
    charSet.insert(s2.begin(), s2.end());
    std::string result(charSet.begin(), charSet.end());
    return result;
}

int main() {
    std::string a = "xyaabbbccccdefww";
    std::string b = "xxxxyyyyabklmopq";
    std::cout << longest(a, b) << std::endl;

    a = "abcdefghijklmnopqrstuvwxyz";
    std::cout << longest(a, a) << std::endl;

    return 0;
}