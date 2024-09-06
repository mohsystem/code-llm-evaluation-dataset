#include <iostream>
#include <algorithm>

std::string shortestPalindrome(std::string s) {
    std::string rev_s = s;
    std::reverse(rev_s.begin(), rev_s.end());
    for (int i = 0; i <= s.length(); i++) {
        if (s.compare(0, s.length() - i, rev_s, i, s.length() - i) == 0) {
            return rev_s.substr(0, i) + s;
        }
    }
    return "";
}

int main() {
    std::string s = "aacecaaa";
    std::cout << shortestPalindrome(s);
    return 0;
}