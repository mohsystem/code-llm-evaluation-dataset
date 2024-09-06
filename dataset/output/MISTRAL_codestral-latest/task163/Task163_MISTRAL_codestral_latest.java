public class Task163_MISTRAL_codestral_latest {
    public static int longestRun(int[] arr) {
        if (arr.length == 0) {
            return 0;
        }
        int longest = 1;
        int current = 1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == arr[i-1] + 1 || arr[i] == arr[i-1] - 1) {
                current++;
            } else {
                longest = Math.max(longest, current);
                current = 1;
            }
        }
        return Math.max(longest, current);
    }
}