public class Main {
    public static int longestRun(int[] arr) {
        if (arr.length == 0) {
            return 0;
        }
        java.util.Arrays.sort(arr);
        int longest_run = 1;
        int current_run = 1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - arr[i-1] == 1) {
                current_run += 1;
            } else {
                longest_run = Math.max(longest_run, current_run);
                current_run = 1;
            }
        }
        return Math.max(longest_run, current_run);
    }
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 5, 6, 7, 8, 9};
        System.out.println(longestRun(arr));
    }
}