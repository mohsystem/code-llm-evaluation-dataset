class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        int lastInvalid = -1;
        stack<int> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                if (stack.empty()) {
                    lastInvalid = i;
                } else {
                    stack.pop();
                    if (stack.empty()) {
                        max = max > i - lastInvalid ? max : i - lastInvalid;
                    } else {
                        max = max > i - stack.top() ? max : i - stack.top();
                    }
                }
            }
        }
        return max;
    }
};