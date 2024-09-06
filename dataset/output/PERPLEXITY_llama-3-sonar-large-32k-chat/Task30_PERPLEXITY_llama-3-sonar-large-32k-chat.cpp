#include <iostream>
#include <set>
#include <string>
#include <algorithm>

std::string longest(const std::string& a, const std::string& b) {
    std::set<char> set;
    for (char c : a) set.insert(c);
    for (char c : b) set.insert(c);
    std::string result;
    for (char c : set) result += c;
    std::sort(result.begin(), result.end());
    return result;
}

int main() {
    std::cout << longest("xyaabbbccccdefww", "xxxxyyyyabklmopq") << std::endl;
    std::cout << longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz") << std::endl;
    return 0;
}