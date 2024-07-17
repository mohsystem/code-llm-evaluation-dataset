
class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        int n = nums.length;
        int[] dp = Arrays.copyOf(nums, n);
        Deque<Integer> dq = new ArrayDeque<>();
        
        int maxSum = nums[0];
        for (int i = 0; i < n; i++) {
            if (!dq.isEmpty() && i - dq.peekFirst() > k) {
                dq.pollFirst();
            }
            
            if (!dq.isEmpty()) {
                dp[i] = Math.max(dp[i], nums[i] + dp[dq.peekFirst()]);
            }
            
            while (!dq.isEmpty() && dp[dq.peekLast()] <= dp[i]) {
                dq.pollLast();
            }
            
            if (dp[i] > 0) {
                dq.offerLast(i);
            }
            
            maxSum = Math.max(maxSum, dp[i]);
        }
        
        return maxSum;
    }
}
