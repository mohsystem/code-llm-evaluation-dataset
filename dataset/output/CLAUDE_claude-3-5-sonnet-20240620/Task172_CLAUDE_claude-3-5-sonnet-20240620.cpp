
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    int distinctEchoSubstrings(std::string text) {
        int n = text.length();
        std::unordered_set<std::string> result;
        
        for (int i = 0; i < n; i++) {
            for (int length = 1; length <= (n - i) / 2; length++) {
                if (text.substr(i, length) == text.substr(i + length, length)) {
                    result.insert(text.substr(i, 2 * length));
                }
            }
        }
        
        return result.size();
    }
};

int main() {
    Solution solution;
    std::cout << solution.distinctEchoSubstrings("abcabcabc") << std::endl;  // Output: 3
    std::cout << solution.distinctEchoSubstrings("leetcodeleetcode") << std::endl;  // Output: 2
    return 0;
}
