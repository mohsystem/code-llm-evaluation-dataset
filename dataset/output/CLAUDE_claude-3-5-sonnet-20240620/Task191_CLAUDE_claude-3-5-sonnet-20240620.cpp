
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> stack;
        stack.push(-1);
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxLength = std::max(maxLength, i - stack.top());
                }
            }
        }
        
        return maxLength;
    }
};

int main() {
    Solution solution;
    std::cout << solution.longestValidParentheses("(()") << std::endl;  // Output: 2
    std::cout << solution.longestValidParentheses(")()())") << std::endl;  // Output: 4
    std::cout << solution.longestValidParentheses("") << std::endl;  // Output: 0
    return 0;
}
