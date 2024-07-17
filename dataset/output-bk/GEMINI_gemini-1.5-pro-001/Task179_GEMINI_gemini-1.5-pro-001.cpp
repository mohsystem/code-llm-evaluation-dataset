class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n * k == 0) {
            return {};
        }
        if (k == 1) {
            return nums;
        }

        vector<int> left(n);
        left[0] = nums[0];
        for (int i = 1; i < n; i++) {
            // at each k steps, set left[i] to nums[i]
            if (i % k == 0) {
                left[i] = nums[i];
            } else {
                left[i] = max(left[i - 1], nums[i]);
            }
        }

        vector<int> right(n);
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            // at each (k - 1), k - 2, etc. steps, set right[i] to nums[i]
            if ((i + 1) % k == 0) {
                right[i] = nums[i];
            } else {
                right[i] = max(right[i + 1], nums[i]);
            }
        }

        vector<int> output(n - k + 1);
        for (int i = 0; i < n - k + 1; i++) {
            output[i] = max(left[i + k - 1], right[i]);
        }

        return output;
    }
};