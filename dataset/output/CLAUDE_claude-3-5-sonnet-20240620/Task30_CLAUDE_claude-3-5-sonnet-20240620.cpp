
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

std::string longest(const std::string &s1, const std::string &s2) {
    std::set<char> chars;
    for (char c : s1 + s2) {
        chars.insert(c);
    }
    std::string result(chars.begin(), chars.end());
    std::sort(result.begin(), result.end());
    return result;
}

int main() {
    std::cout << longest("xyaabbbccccdefww", "xxxxyyyyabklmopq") << std::endl;
    std::cout << longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz") << std::endl;
    return 0;
}
