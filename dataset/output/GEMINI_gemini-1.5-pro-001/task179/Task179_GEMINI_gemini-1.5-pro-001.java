class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0) {
            return new int[0];
        }
        if (k == 1) {
            return nums;
        }
        
        int n = nums.length;
        int[] max_left = new int[n];
        int[] max_right = new int[n];
        max_left[0] = nums[0];
        max_right[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            max_left[i] = (i % k == 0) ? nums[i] : Math.max(max_left[i - 1], nums[i]);
            int j = n - i - 1;
            max_right[j] = ((j + 1) % k == 0) ? nums[j] : Math.max(max_right[j + 1], nums[j]);
        }

        int[] result = new int[n - k + 1];
        for (int i = 0; i < n - k + 1; i++) {
            result[i] = Math.max(max_right[i], max_left[i + k - 1]);
        }

        return result;
    }
}