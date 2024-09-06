import java.util.Deque;
import java.util.LinkedList;

public class Task178_OPENAI_gpt_4o {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] prefixSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        Deque<Integer> deque = new LinkedList<>();
        int minLength = Integer.MAX_VALUE;

        for (int i = 0; i <= n; i++) {
            while (!deque.isEmpty() && prefixSum[i] - prefixSum[deque.peekFirst()] >= k) {
                minLength = Math.min(minLength, i - deque.pollFirst());
            }
            while (!deque.isEmpty() && prefixSum[i] <= prefixSum[deque.peekLast()]) {
                deque.pollLast();
            }
            deque.offerLast(i);
        }

        return minLength == Integer.MAX_VALUE ? -1 : minLength;
    }

    public static void main(String[] args) {
        Task178_OPENAI_gpt_4o sa = new Task178_OPENAI_gpt_4o();
        System.out.println(sa.shortestSubarray(new int[] {1}, 1)); // Output: 1
        System.out.println(sa.shortestSubarray(new int[] {1, 2}, 4)); // Output: -1
        System.out.println(sa.shortestSubarray(new int[] {2, -1, 2}, 3)); // Output: 3
    }
}