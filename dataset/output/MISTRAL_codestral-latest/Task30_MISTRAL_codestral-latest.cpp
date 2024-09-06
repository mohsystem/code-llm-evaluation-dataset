#include <iostream>
#include <string>
#include <set>
#include <algorithm>

std::string longest(std::string s1, std::string s2) {
    std::string s = s1 + s2;
    std::set<char> uniqueChars(s.begin(), s.end());
    std::string result(uniqueChars.begin(), uniqueChars.end());
    std::sort(result.begin(), result.end());
    return result;
}

int main() {
    std::cout << longest("xyaabbbccccdefww", "xxxxyyyyabklmopq");
    return 0;
}