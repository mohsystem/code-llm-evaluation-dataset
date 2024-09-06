
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int distinctEchoSubstrings(String text) {
        int n = text.length();
        Set<String> result = new HashSet<>();
        
        for (int i = 0; i < n; i++) {
            for (int length = 1; length <= (n - i) / 2; length++) {
                if (text.substring(i, i + length).equals(text.substring(i + length, i + 2 * length))) {
                    result.add(text.substring(i, i + 2 * length));
                }
            }
        }
        
        return result.size();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.distinctEchoSubstrings("abcabcabc"));  // Output: 3
        System.out.println(solution.distinctEchoSubstrings("leetcodeleetcode"));  // Output: 2
    }
}
