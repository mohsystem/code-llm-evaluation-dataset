class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.length() + 1];
        memset(dp, 0, sizeof(dp));
        stack<int> st;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    int j = st.top();
                    st.pop();
                    dp[i + 1] = dp[j] + i - j + 1;
                    maxLength = max(maxLength, dp[i + 1]);
                }
            }
        }
        return maxLength;
    }
};