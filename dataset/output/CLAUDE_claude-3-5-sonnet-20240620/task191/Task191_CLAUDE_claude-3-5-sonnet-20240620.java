
class Solution {
    public int longestValidParentheses(String s) {
        java.util.Stack<Integer> stack = new java.util.Stack<>();
        stack.push(-1);
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxLength = Math.max(maxLength, i - stack.peek());
                }
            }
        }
        
        return maxLength;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.longestValidParentheses("(()"));  // Output: 2
        System.out.println(solution.longestValidParentheses(")()())"));  // Output: 4
        System.out.println(solution.longestValidParentheses(""));  // Output: 0
    }
}
