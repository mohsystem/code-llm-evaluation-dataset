#include <stack>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> stack;
    stack.push(-1);
    int maxLength = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stack.push(i);
        } else {
            stack.pop();
            if (!stack.empty()) {
                maxLength = max(maxLength, i - stack.top());
            } else {
                stack.push(i);
            }
        }
    }
    return maxLength;
}