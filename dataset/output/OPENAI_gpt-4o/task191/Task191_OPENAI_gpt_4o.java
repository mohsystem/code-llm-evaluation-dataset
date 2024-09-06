// Java code for finding length of the longest valid parentheses substring

public class Task191_OPENAI_gpt_4o {
    public static int longestValidParentheses(String s) {
        int max_length = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.isEmpty()) {
                    stack.push(i);
                } else {
                    max_length = Math.max(max_length, i - stack.peek());
                }
            }
        }
        return max_length;
    }

    public static void main(String[] args) {
        String s = "(()";  // Example 1
        System.out.println(longestValidParentheses(s));  // Output: 2
        s = ")()())";  // Example 2
        System.out.println(longestValidParentheses(s));  // Output: 4
        s = "";  // Example 3
        System.out.println(longestValidParentheses(s));  // Output: 0
    }
}