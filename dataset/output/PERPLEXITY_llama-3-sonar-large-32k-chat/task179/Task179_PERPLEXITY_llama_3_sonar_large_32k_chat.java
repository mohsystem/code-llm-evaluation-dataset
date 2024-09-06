import java.util.*;

public class Task179_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return new int[0];
        }
        if (k == 0) {
            return new int[0];
        }
        
        int[] output = new int[nums.length - k + 1];
        Deque<Integer> dq = new LinkedList<>();
        
        for (int i = 0; i < nums.length; i++) {
            while (!dq.isEmpty() && dq.peek() < i - k + 1) {
                dq.poll();
            }
            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) {
                dq.pollLast();
            }
            dq.offer(i);
            
            if (i >= k - 1) {
                output[i - k + 1] = nums[dq.peek()];
            }
        }
        
        return output;
    }
}