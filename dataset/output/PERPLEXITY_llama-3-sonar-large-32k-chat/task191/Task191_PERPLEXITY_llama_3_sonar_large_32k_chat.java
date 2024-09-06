public class Task191_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public int longestValidParentheses(String s) {
        int max_len = 0;
        int last_invalid = -1;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                if (stack.isEmpty()) {
                    last_invalid = i;
                } else {
                    stack.pop();
                    if (stack.isEmpty()) {
                        max_len = Math.max(max_len, i - last_invalid);
                    } else {
                        max_len = Math.max(max_len, i - stack.peek());
                    }
                }
            }
        }
        return max_len;
    }
}