public class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int res = n + 1;
        Deque<Integer> queue = new LinkedList<>();
        for (int i = 0; i <= n; i++) {
            while (!queue.isEmpty() && prefix[i] - prefix[queue.peek()] >= k) {
                res = Math.min(res, i - queue.poll());
            }
            while (!queue.isEmpty() && prefix[queue.peekLast()] >= prefix[i]) {
                queue.pollLast();
            }
            queue.offer(i);
        }
        return res <= n ? res : -1;
    }
}