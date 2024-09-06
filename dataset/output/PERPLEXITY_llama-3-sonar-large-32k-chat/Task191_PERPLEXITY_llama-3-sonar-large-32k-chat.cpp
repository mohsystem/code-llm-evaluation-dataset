class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        int last_invalid = -1;
        stack<int> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                if (stack.empty()) {
                    last_invalid = i;
                } else {
                    stack.pop();
                    if (stack.empty()) {
                        max_len = max(max_len, i - last_invalid);
                    } else {
                        max_len = max(max_len, i - stack.top());
                    }
                }
            }
        }
        return max_len;
    }
};