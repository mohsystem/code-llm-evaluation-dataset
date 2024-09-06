// C++ code for finding length of the longest valid parentheses substring

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);
    int max_length = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                max_length = max(max_length, i - stk.top());
            }
        }
    }

    return max_length;
}

int main() {
    string s = "(()";  // Example 1
    cout << longestValidParentheses(s) << endl;  // Output: 2
    s = ")()())";  // Example 2
    cout << longestValidParentheses(s) << endl;  // Output: 4
    s = "";  // Example 3
    cout << longestValidParentheses(s) << endl;  // Output: 0
    return 0;
}