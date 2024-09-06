import java.util.ArrayDeque;
import java.util.Deque;
class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] preSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        int res = Integer.MAX_VALUE;
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n + 1; i++) {
            while (!q.isEmpty() && preSum[i] - preSum[q.peekFirst()] >= k) {
                res = Math.min(res, i - q.pollFirst());
            }
            while (!q.isEmpty() && preSum[i] <= preSum[q.peekLast()]) {
                q.pollLast();
            }
            q.offerLast(i);
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}