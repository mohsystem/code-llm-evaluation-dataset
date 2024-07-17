int longestValidParentheses(char * s){
    int n = strlen(s);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    int *stack = (int *)malloc(sizeof(int) * (n + 1));
    int top = -1;
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            if (top != -1) {
                int j = stack[top--];
                dp[i + 1] = dp[j] + i - j + 1;
                maxLength = fmax(maxLength, dp[i + 1]);
            }
        }
    }
    free(stack);
    return maxLength;
}