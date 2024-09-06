import java.util.ArrayDeque;

class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        
        for (int i = 0; i < n; i++) {
            // Remove outdated elements from the deque
            while (!deque.isEmpty() && deque.peekFirst() < i - k) {
                deque.pollFirst();
            }
            
            // Calculate dp[i + 1] based on the maximum value in the deque
            dp[i + 1] = Math.max(dp[i + 1], Math.max(nums[i], (deque.isEmpty() ? 0 : dp[deque.peekFirst()]) + nums[i]));
            
            // Maintain the deque to store indices of potential maximum values
            while (!deque.isEmpty() && dp[deque.peekLast()] <= dp[i + 1]) {
                deque.pollLast();
            }
            deque.offerLast(i + 1);
        }
        
        int maxSum = Integer.MIN_VALUE;
        for (int i = 1; i <= n; i++) {
            maxSum = Math.max(maxSum, dp[i]);
        }
        return maxSum;
    }
}