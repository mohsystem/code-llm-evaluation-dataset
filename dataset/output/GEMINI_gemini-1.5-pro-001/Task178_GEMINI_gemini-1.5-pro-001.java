import java.util.Deque;
import java.util.LinkedList;

class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] preSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        int res = Integer.MAX_VALUE;
        Deque<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n + 1; i++) {
            while (!queue.isEmpty() && preSum[i] - preSum[queue.peekFirst()] >= k) {
                res = Math.min(res, i - queue.pollFirst());
            }
            while (!queue.isEmpty() && preSum[i] <= preSum[queue.peekLast()]) {
                queue.pollLast();
            }
            queue.offerLast(i);
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}