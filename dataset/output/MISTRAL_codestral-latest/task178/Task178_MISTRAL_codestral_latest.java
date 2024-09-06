import java.util.Deque;
import java.util.LinkedList;

public class Task178_MISTRAL_codestral_latest {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] prefixSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int minLength = n + 1;
        Deque<Integer> monoQueue = new LinkedList<>();
        for (int i = 0; i <= n; i++) {
            while (!monoQueue.isEmpty() && prefixSum[i] - prefixSum[monoQueue.peekFirst()] >= k) {
                minLength = Math.min(minLength, i - monoQueue.pollFirst());
            }
            while (!monoQueue.isEmpty() && prefixSum[i] <= prefixSum[monoQueue.peekLast()]) {
                monoQueue.pollLast();
            }
            monoQueue.addLast(i);
        }

        return minLength <= n ? minLength : -1;
    }
}