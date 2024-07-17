#include <string>
#include <algorithm>

class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        int i = 0;
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                i++;
            }
        }
        if (i == s.length()) {
            return s;
        }
        std::string suffix = s.substr(i);
        std::string prefix(suffix);
        std::reverse(prefix.begin(), prefix.end());
        return prefix + shortestPalindrome(s.substr(0, i)) + suffix;
    }
};