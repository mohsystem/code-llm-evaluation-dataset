public class Task177_MISTRAL_codestral_latest {
    public int maxSumSubsequence(int[] nums, int k) {
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            dp[i] = Math.max(dp[i-1], nums[i]);
            for (int j = i-1; j >= Math.max(-1, i-k-1); j--) {
                dp[i] = Math.max(dp[i], dp[j] + nums[i]);
            }
        }
        int maxSum = dp[0];
        for (int i = 1; i < dp.length; i++) {
            maxSum = Math.max(maxSum, dp[i]);
        }
        return maxSum;
    }
}