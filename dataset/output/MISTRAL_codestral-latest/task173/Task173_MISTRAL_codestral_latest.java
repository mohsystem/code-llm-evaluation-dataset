import java.util.HashSet;
import java.util.Set;

public class Task173_MISTRAL_codestral_latest {
    public String longestDupSubstring(String s) {
        int n = s.length();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = s.charAt(i) - 'a';
        }
        int a = 26;
        long mod = (long) Math.pow(2, 32);

        int check(int length) {
            long h = 0;
            for (int i = 0; i < length; i++) {
                h = (h * a + nums[i]) % mod;
            }
            Set<Long> seen = new HashSet<>();
            seen.add(h);
            long aL = 1;
            for (int i = 1; i <= length; i++) {
                aL = (aL * a) % mod;
            }
            for (int start = 1; start <= n - length; start++) {
                h = (h * a - nums[start - 1] * aL + nums[start + length - 1]) % mod;
                if (seen.contains(h)) {
                    return start;
                }
                seen.add(h);
            }
            return -1;
        }

        int start = -1, length = 0;
        for (int k = 1; k < n; k++) {
            int pos = check(k);
            if (pos != -1 && k > length) {
                start = pos;
                length = k;
            }
        }
        return start != -1 ? s.substring(start, start + length) : "";
    }
}