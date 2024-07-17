class Solution {
    public int longestValidParentheses(String s) {
        int[] dp = new int[s.length() + 1];
        Stack<Integer> stack = new Stack<>();
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                if (!stack.isEmpty()) {
                    int j = stack.pop();
                    dp[i + 1] = dp[j] + i - j + 1;
                    maxLength = Math.max(maxLength, dp[i + 1]);
                }
            }
        }
        return maxLength;
    }
}