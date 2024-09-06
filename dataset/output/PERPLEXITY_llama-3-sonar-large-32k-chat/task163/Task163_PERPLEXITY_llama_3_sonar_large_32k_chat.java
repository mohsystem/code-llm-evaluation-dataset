public class Task163_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static int longestRun(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        java.util.Arrays.sort(nums);
        int longest_run = 1;
        int current_run = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - nums[i-1] == 1) {
                current_run += 1;
            } else {
                longest_run = Math.max(longest_run, current_run);
                current_run = 1;
            }
        }
        return Math.max(longest_run, current_run);
    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 5, 6, 7, 8, 9};
        System.out.println(longestRun(nums));
    }
}