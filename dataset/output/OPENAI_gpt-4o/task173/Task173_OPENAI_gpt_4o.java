// Java code
import java.util.*;

public class Task173_OPENAI_gpt_4o {
    public static void main(String[] args) {
        System.out.println(longestDupSubstring("banana"));  // Output: "ana"
        System.out.println(longestDupSubstring("abcd"));    // Output: ""
    }

    public static String longestDupSubstring(String s) {
        int left = 1, right = s.length() - 1;
        String result = "";
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            String duplicate = searchSubstring(s, mid);
            if (!duplicate.isEmpty()) {
                result = duplicate;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }

    private static String searchSubstring(String s, int length) {
        Map<Long, List<Integer>> hashes = new HashMap<>();
        long p = 31, m = (long) (1e9 + 7);
        long pPow = 1, currHash = 0;

        for (int i = 0; i < length; ++i) {
            currHash = (currHash + (s.charAt(i) - 'a' + 1) * pPow) % m;
            pPow = (pPow * p) % m;
        }
        hashes.put(currHash, new ArrayList<>(Arrays.asList(0)));
        
        pPow = 1;
        for (int j = 1; j < length; ++j) pPow = (pPow * p) % m;

        for (int i = 1; i <= s.length() - length; ++i) {
            currHash = (currHash - (s.charAt(i - 1) - 'a' + 1) * pPow % m + m) % m;
            currHash = (currHash * p + (s.charAt(i + length - 1) - 'a' + 1)) % m;
            
            if (hashes.containsKey(currHash)) {
                for (int start : hashes.get(currHash)) {
                    if (s.substring(start, start + length).equals(s.substring(i, i + length))) {
                        return s.substring(start, start + length);
                    }
                }
            }

            hashes.computeIfAbsent(currHash, k -> new ArrayList<>()).add(i);
        }
        return "";
    }
}