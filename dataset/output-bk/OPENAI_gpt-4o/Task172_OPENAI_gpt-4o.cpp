#include <iostream>
#include <unordered_set>
#include <string>

int distinctConcatenations(const std::string& text) {
    std::unordered_set<std::string> seen;
    int length = text.length();
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j <= length; ++j) {
            std::string sub = text.substr(i, j - i);
            if (sub.length() % 2 == 0) {
                int halfLen = sub.length() / 2;
                if (sub.substr(0, halfLen) == sub.substr(halfLen)) {
                    seen.insert(sub);
                }
            }
        }
    }
    return seen.size();
}

int main() {
    std::cout << distinctConcatenations("abcabcabc") << std::endl; // Output: 3
    std::cout << distinctConcatenations("leetcodeleetcode") << std::endl; // Output: 2
    return 0;
}