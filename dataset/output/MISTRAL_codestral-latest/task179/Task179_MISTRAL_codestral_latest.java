import java.util.*;

public class Task179_MISTRAL_codestral_latest {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] result = new int[n - k + 1];
        Deque<Integer> window = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            while (!window.isEmpty() && window.peek() <= i - k) {
                window.poll();
            }
            while (!window.isEmpty() && nums[window.peekLast()] < nums[i]) {
                window.pollLast();
            }
            window.offer(i);
            if (i >= k - 1) {
                result[i - k + 1] = nums[window.peek()];
            }
        }

        return result;
    }
}