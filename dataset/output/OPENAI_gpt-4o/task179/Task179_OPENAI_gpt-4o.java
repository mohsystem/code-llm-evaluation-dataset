import java.util.*;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return new int[0];
        }

        int n = nums.length;
        int[] result = new int[n - k + 1];
        Deque<Integer> deq = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            while (!deq.isEmpty() && deq.peekFirst() < i - k + 1) {
                deq.pollFirst();
            }
            while (!deq.isEmpty() && nums[deq.peekLast()] < nums[i]) {
                deq.pollLast();
            }
            deq.offerLast(i);
            
            if (i >= k - 1) {
                result[i - k + 1] = nums[deq.peekFirst()];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        
        int[] nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
        int k1 = 3;
        System.out.println(Arrays.toString(sol.maxSlidingWindow(nums1, k1)));  // [3,3,5,5,6,7]

        int[] nums2 = {1};
        int k2 = 1;
        System.out.println(Arrays.toString(sol.maxSlidingWindow(nums2, k2)));  // [1]
    }
}