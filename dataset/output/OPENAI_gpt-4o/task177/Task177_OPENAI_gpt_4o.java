import java.util.Deque;
import java.util.LinkedList;

public class Task177_OPENAI_gpt_4o {
    public static void main(String[] args) {
        System.out.println(maxSubsequenceSum(new int[]{10, 2, -10, 5, 20}, 2));  // Output: 37
        System.out.println(maxSubsequenceSum(new int[]{-1, -2, -3}, 1));  // Output: -1
        System.out.println(maxSubsequenceSum(new int[]{10, -2, -10, -5, 20}, 2));  // Output: 23
    }

    public static int maxSubsequenceSum(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        Deque<Integer> deque = new LinkedList<>();
        deque.add(0);
        
        for (int i = 1; i < n; i++) {
            while (!deque.isEmpty() && deque.peekFirst() < i - k) {
                deque.pollFirst();
            }
            dp[i] = nums[i] + (deque.isEmpty() ? 0 : dp[deque.peekFirst()]);
            while (!deque.isEmpty() && dp[i] >= dp[deque.peekLast()]) {
                deque.pollLast();
            }
            deque.addLast(i);
        }
        
        int maxSum = Integer.MIN_VALUE;
        for (int num : dp) {
            maxSum = Math.max(maxSum, num);
        }
        
        return maxSum;
    }
}