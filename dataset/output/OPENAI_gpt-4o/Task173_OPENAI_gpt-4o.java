import java.util.HashSet;

public class Main {
    public static String longestDupSubstring(String s) {
        int left = 1, right = s.length() - 1;
        String res = "";
        while (left <= right) {
            int mid = (left + right) / 2;
            String dup = search(s, mid);
            if (dup != null) {
                res = dup;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }

    private static String search(String s, int length) {
        HashSet<String> seen = new HashSet<>();
        for (int i = 0; i + length <= s.length(); i++) {
            String current = s.substring(i, i + length);
            if (seen.contains(current)) {
                return current;
            }
            seen.add(current);
        }
        return null;
    }

    public static void main(String[] args) {
        String s1 = "banana";
        String s2 = "abcd";
        System.out.println(longestDupSubstring(s1)); // Output: "ana"
        System.out.println(longestDupSubstring(s2)); // Output: ""
    }
}