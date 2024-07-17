import java.util.*;

public class Main {
    public static int maxSubsequenceSum(int[] nums, int k) {
        int n = nums.length;
        if (n == 0) return 0;

        int[] dp = new int[n];
        dp[0] = nums[0];
        Deque<Integer> deque = new LinkedList<>();
        deque.add(0);

        for (int i = 1; i < n; i++) {
            if (!deque.isEmpty() && deque.peekFirst() < i - k) {
                deque.pollFirst();
            }
            dp[i] = nums[i] + dp[deque.peekFirst()];
            while (!deque.isEmpty() && dp[i] >= dp[deque.peekLast()]) {
                deque.pollLast();
            }
            deque.addLast(i);
        }

        int result = Integer.MIN_VALUE;
        for (int val : dp) {
            result = Math.max(result, val);
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(maxSubsequenceSum(new int[]{10, 2, -10, 5, 20}, 2));  // 37
        System.out.println(maxSubsequenceSum(new int[]{-1, -2, -3}, 1));        // -1
        System.out.println(maxSubsequenceSum(new int[]{10, -2, -10, -5, 20}, 2)); // 23
    }
}