class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int p1 = 0, p2 = 0;
        int i = 0, j = 0;
        vector<int> nums;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums.push_back(nums1[i++]);
            } else {
                nums.push_back(nums2[j++]);
            }
        }
        while (i < m) {
            nums.push_back(nums1[i++]);
        }
        while (j < n) {
            nums.push_back(nums2[j++]);
        }

        int k = (m + n) / 2;
        if ((m + n) % 2 == 0) {
            return (nums[k] + nums[k - 1]) / 2.0;
        } else {
            return nums[k];
        }
    }
};