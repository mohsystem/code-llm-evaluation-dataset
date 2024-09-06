public class Task178_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int res = n + 1;
        Deque<Integer> queue = new LinkedList<>();
        for (int i = 0; i <= n; i++) {
            while (!queue.isEmpty() && prefixSum[i] - prefixSum[queue.peek()] >= k) {
                res = Math.min(res, i - queue.poll());
            }
            while (!queue.isEmpty() && prefixSum[i] <= prefixSum[queue.peekLast()]) {
                queue.pollLast();
            }
            queue.offer(i);
        }
        return res <= n ? res : -1;
    }
}