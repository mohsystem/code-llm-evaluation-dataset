class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            while (!q.isEmpty() && i - q.peekFirst() > k + 1) {
                q.pollFirst();
            }
            dp[i] = Math.max(dp[i - 1], dp[q.isEmpty() ? 0 : q.peekFirst()] + nums[i - 1]);
            while (!q.isEmpty() && dp[q.peekLast()] <= dp[i]) {
                q.pollLast();
            }
            q.offerLast(i);
        }
        return dp[n];
    }
}